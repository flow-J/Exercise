# coding: utf-8
from datetime import datetime
from flask.ext.wtf import Form
from wtforms import StringField, SubmitField, PasswordField, HiddenField
from wtforms.validators import Required, Email, EqualTo

class NameForm(Form):
    name = StringField('What is your name?', validators=[Required()])
    submit = SubmitField('Submit')

class EmailForm(Form):
    email = StringField('Enter your email.', validators=[Email()])
    password = PasswordField('password', validators=[Required(), EqualTo('confirm_password', message='password')])
    confirm_password = PasswordField('confirm password', validators=[Required()])

    submit = SubmitField('Submit')


class EditProfileForm(Form): # 资料编辑器
    name = StringFiled('Real name', validators=[Length(0, 64)])
    location = StringField('Location', validators=[Length(0, 64)])
    about_me = TextAreaField('About me')
    submit = SubmitField('Submit')
