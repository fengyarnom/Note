from flask import Flask,render_template
from flask_sqlalchemy import SQLAlchemy

from config import Config

app = Flask(__name__)
db = SQLAlchemy(app)

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(20), unique=True, nullable=False)
    password = db.Column(db.String(20), nullable=False)

app.config.from_object(Config)
@app.route('/')
def index():
    # return '<h1>Hello</h1>'
    title = 'Flask Web APP'
    content = [
        'Item1',
        'Item2',
        'Item3'
    ]
    admin = User(username='admin', password='root')
    db.session.add(admin)
    u = User.query.all()
    return render_template('index.html',title=title,content=content,u=u)

if __name__ == '__main__':

    # app.run(debug=True) //实时更新
    # app.run(host='0.0.0.0' port=3000) //其他设备也可以显示
    app.run(debug=True,host='0.0.0.0',port=3000)

    # db.create_all()

