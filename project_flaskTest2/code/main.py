from flask import Flask, render_template, request, redirect, url_for, session
import sqlite3

app = Flask(__name__)
app.secret_key = 'your_secret_key'

# Функція для з'єднання з базою даних SQLite
def connect_db():
    return sqlite3.connect(app.root_path + '/bookkeeping.db')

# Створення всіх таблиць
def create_all_tables():
    create_user_table()
    create_companies_table()
    create_news_table()
    create_documents_table()
    print("All tables created successfully!")

# Створення таблиці користувачів
def create_user_table():
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, password TEXT)')

# Реєстрація нового користувача
def register_user(username, password):
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('INSERT INTO users (username, password) VALUES (?, ?)', (username, password))
        con.commit()

# Створення таблиці компаній
def create_companies_table():
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('CREATE TABLE IF NOT EXISTS companies (id INTEGER PRIMARY KEY, name TEXT)')

# Реєстрація нової компанії
def register_company(name):
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('INSERT INTO companies (name) VALUES (?)', (name,))
        con.commit()

# Створення таблиці новин
def create_news_table():
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('CREATE TABLE IF NOT EXISTS news (id INTEGER PRIMARY KEY, title TEXT)')

# Додавання новини
def add_news(title):
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('INSERT INTO news (title) VALUES (?)', (title,))
        con.commit()

# Створення таблиці документів
def create_documents_table():
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('CREATE TABLE IF NOT EXISTS documents (id INTEGER PRIMARY KEY, title TEXT)')

# Додавання документу
def add_document(title):
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('INSERT INTO documents (title) VALUES (?)', (title,))
        con.commit()


# Сторінка "Документи"

@app.route('/documents', methods=['GET', 'POST'])
def documents():
    if 'user_id' in session:
        if request.method == 'POST':
            document_title = request.form['document_title']
            add_document(document_title)
            # Після додавання документу перенаправити користувача на сторінку зі списком документів
            return redirect(url_for('documents'))

        # Отримати список документів з бази даних
        documents_list = get_documents()

        return render_template('documents.html', documents_list=documents_list)
    else:
        return redirect(url_for('login'))

# Додайте функцію для отримання документів з бази даних
def get_documents():
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('SELECT * FROM documents')
        documents_list = cur.fetchall()
    return documents_list

# Сторінка "Новини"
@app.route('/accounting_news', methods=['GET', 'POST'])
def accounting_news():
    if 'user_id' in session:
        if request.method == 'POST':
            news_title = request.form['news_title']
            add_news(news_title)
            # Після додавання новини перенаправити користувача на сторінку зі списком новин
            return redirect(url_for('accounting_news'))

        # Отримати список новин з бази даних
        news_list = get_news()

        return render_template('accounting_news.html', news_list=news_list)
    else:
        return redirect(url_for('login'))

# Додайте функцію для отримання новин з бази даних
def get_news():
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('SELECT * FROM news')
        news_list = cur.fetchall()
    return news_list

# Сторінка "Компанії"
@app.route('/companies', methods=['GET', 'POST'])
def companies():
    if 'user_id' in session:
        if request.method == 'POST':
            company_name = request.form['company_name']
            register_company(company_name)
            # Після додавання компанії перенаправити користувача на сторінку зі списком компаній
            return redirect(url_for('companies'))

        # Отримати список компаній з бази даних
        companies_list = get_companies()

        return render_template('companies.html', companies_list=companies_list)
    else:
        return redirect(url_for('login'))

# Додайте функцію для отримання компаній з бази даних
def get_companies():
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('SELECT * FROM companies')
        companies_list = cur.fetchall()
    return companies_list

# Перевірка користувача для входу
def authenticate_user(username, password):
    with connect_db() as con:
        cur = con.cursor()
        cur.execute('SELECT * FROM users WHERE username=? AND password=?', (username, password))
        user = cur.fetchone()
        return user

# Головна сторінка
@app.route('/')
def home():
    return render_template('index.html')

# Сторінка входу
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        user = authenticate_user(username, password)

        if user:
            session['user_id'] = user[0]
            return redirect(url_for('dashboard'))
        else:
            return render_template('login.html', error='Invalid credentials')

    return render_template('login.html', error=None)

# Сторінка реєстрації
@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        register_user(username, password)
        return redirect(url_for('login'))

    return render_template('register.html')

# Сторінка виходу
@app.route('/logout')
def logout():
    session.clear()
    return redirect(url_for('home'))

# Захищена сторінка (потребує входу в систему)
@app.route('/dashboard')
def dashboard():
    if 'user_id' in session:
        # Отримання списку документів з бази даних
        documents_list = get_documents()

        # Отримання списку компаній з бази даних
        companies_list = get_companies()

        # Отримання списку новин з бази даних
        news_list = get_news()

        return render_template('dashboard.html', documents_list=documents_list, companies_list=companies_list, news_list=news_list)
    else:
        return redirect(url_for('login'))

# Створення всіх таблиць перед додаванням даних
create_all_tables()

# Додавання даних при запуску
#register_user('admin', 'admin')
#register_company('testCompany')
#add_news('TestNews')
#add_document('TestDoc')

if __name__ == '__main__':
    app.run(debug=True)
