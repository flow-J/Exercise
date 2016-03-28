# coding: utf-8
from datetime import datetime
from flask import Flask, render_template
from flask.ext.bootstrap import Bootstrap
from flask.ext.moment import Moment
from flask.ext.wtf import Form
from wtforms import StringField, SubmitField, PasswordField
from wtforms.validators import Required, Email

app = Flask(__name__)
app.config['SECRET_KEY'] = 'hard to guess string'
bootstrap = Bootstrap(app)
moment = Moment(app)

#**************************** decorate************************************#

@app.route('/user/<name>')
def name(name):
    return render_template('user.html', name= name)
#   return app.send_static_file('a.json')

@app.route('/time')
def time():
    return render_template('time.html',
            time = datetime.utcnow())

@app.route('/', methods=['GET', 'POST'])
def hello():
    name = None
    form = NameForm()
    if form.validate_on_submit():# 首先检查提交的内容是不是为空
        name = form.name.data   #成功后把data里的值赋给name
        form.name.data = ''     #这里把data设为空字符串是因为它是输入框里的参数？(或者字符？)
                                # 如果没有这一步的话输入框被输入一次后不会清空上一次的内容
    return render_template('index.html', form=form, name=name,
            time = datetime.utcnow())

@app.route('/base/')
def base():
    return render_template('base.html')

@app.route('/email/')
def email():
    email = None


@app.errorhandler(404)
def page_not_found(justaword):
    return render_template('404.html'), 404

@app.errorhandler(500)
def server_error(justaword):
    return render_template('500.html'), 500


#***************************************class*****************************#

class NameForm(Form):
    name = StringField('What is your name?', validators=[Required()])# 文本字段 Required()是个验证函数　如果输入框里为空的话就会提示出错

    submit = SubmitField('Submit') # 表单提交按钮

class EmailForm(Form):
    email = StringField('Enter your email.', validators=[Email()])
    password = PasswordField('password', )
    submit = SubmitField('确定')








if __name__ == '__main__':
    app.run(host= '127.0.0.1', port = 7777)
