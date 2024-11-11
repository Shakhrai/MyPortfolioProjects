document.getElementById('programForm').addEventListener('submit', function(event) {
    event.preventDefault();
    
    var form = event.target;
    var formData = new FormData(form);
    var status = document.getElementById('status');
    
    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'upload.php', true);
    xhr.onload = function() {
        if (xhr.status === 200) {
            status.textContent = 'Программа успешно загружена!';
        } else {
            status.textContent = 'Ошибка загрузки программы.';
        }
    };
    xhr.send(formData);
});
