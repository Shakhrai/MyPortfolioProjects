from flask import Flask, render_template, request, url_for, redirect
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///greenVibe.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)


class Rooms(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    room_num = db.Column(db.Integer, nullable=False)
    room_place = db.Column(db.Integer, nullable=False)
    room_desc = db.Column(db.String(300), nullable=False)
    room_price = db.Column(db.Integer, nullable=False)
    is_reserved_room = db.Column(db.Integer, nullable=False)
    img_filename = db.Column(db.String(300),nullable=False)

    def __repr__(self):
        return self.name


@app.route('/')
@app.route('/home')
def index():
    return render_template('main.html')


@app.route('/about')
def history():
    return render_template('about.html')


@app.route('/contact')
def about():
    return render_template('contact.html')


@app.route('/roomReserve')
def album():
    items = Rooms.query.order_by(Rooms.room_num).all()
    return render_template('roomReserve.html', data=items)


@app.route('/login')
def login():
    return render_template('login.html')


@app.route('/signup')
def signup():
    return render_template('signup.html')


@app.route('/crud')
def crud():
    items = Rooms.query.order_by(Rooms.room_num).all()
    return render_template('crud.html', data=items)


@app.route('/create', methods=['POST', 'GET'])
def create():
    if request.method == "POST":
        room_num = request.form['room_num']
        room_place = request.form['room_place']
        room_desc = request.form['room_desc']
        room_price = request.form['room_price']
        is_reserved_room = request.form['is_reserved_room']
        img_filename = request.form['img_filename']
        item = Rooms(room_num=room_num,
                     room_place=room_place,
                     room_desc=room_desc,
                     room_price=room_price,
                     is_reserved_room=is_reserved_room,
                     img_filename=img_filename)

        try:
            db.session.add(item)
            db.session.commit()
            return redirect('/roomReserve')

        except:
            return "ERROR"
    else:
        return render_template('create.html')


@app.route('/crud/<int:id>/update', methods=['GET', 'POST'])
def update(id):
    items = Rooms.query.filter_by(id=id).first()
    if request.method == 'POST':
        if items:
            db.session.delete(items)
            db.session.commit()

            room_num = request.form['room_num']
            room_place = request.form['room_place']
            room_desc = request.form['room_desc']
            room_price = request.form['room_price']
            is_reserved_room = request.form['is_reserved_room']
            img_filename = request.form['img_filename']
            item = Rooms(room_num=room_num,
                         room_place=room_place,
                         room_desc=room_desc,
                         room_price=room_price,
                         is_reserved_room=is_reserved_room,
                         img_filename=img_filename)

            db.session.add(items)
            db.session.commit()
            return redirect('/roomReserve')
        return f"Room with id = {id} Does not exist"

    return render_template('edit.html',  data=items)


@app.route('/crud/<int:id>/delete', methods=['GET', 'POST'])
def delete(id):
    items = Rooms.query.filter_by(id=id).first()
    if request.method == 'POST':
        try:
            db.session.delete(items)
            db.session.commit()
            return redirect('/crud')
        except:
            items(404)

    return render_template('delete.html',data=items)


if __name__ == '__main__':
    app.run(debug=True)
