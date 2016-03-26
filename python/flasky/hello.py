from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello():
    return "<h1> hello, world! </h1>"
#    return app.send_static_file('a.json')

if __name__ == '__main__':
    app.run(host= '127.0.0.1', port = 7777)

