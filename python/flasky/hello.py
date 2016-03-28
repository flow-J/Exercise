from datetime import datetime
from flask import Flask, render_template
from flask.ext.bootstrap import Bootstrap
from flask.ext.moment import Moment

app = Flask(__name__)
app.config['SECRET_KEY'] = 'hard to guess string'
bootstrap = Bootstrap(app)
moment = Moment(app)



@app.route('/user/<name>')
def name(name):
    return render_template('user.html', name= name)
#   return app.send_static_file('a.json')

@app.route('/time')
def time():
    return render_template('time.html',
            time = datetime.utcnow())

@app.route('/')
def hello():
    return render_template('index.html',
            time = datetime.utcnow())

@app.route('/base/')
def base():
    return render_template('base.html')

@app.errorhandler(404)
def page_not_found(justaword):
    return render_template('404.html'), 404

@app.errorhandler(500)
def server_error(justaword):
    return render_template('500.html'), 500

if __name__ == '__main__':
    app.run(host= '127.0.0.1', port = 7777)
