# coding: utf-8
from datetime import datetime
from flask.ext.wtf import Form
from wtforms import StringField, SubmitField, PasswordField, HiddenField, TextAreaField, BooleanField, SelectField
from wtforms.validators import Required, Email, EqualTo, Length, Regexp
from ..models import Role, User

class NameForm(Form):
    name = StringField('What is your name?', validators=[Required()])
    submit = SubmitField('Submit')

class EmailForm(Form):
    email = StringField('Enter your email.', validators=[Email()])
    password = PasswordField('password', validators=[Required(), EqualTo('confirm_password', message='password')])
    confirm_password = PasswordField('confirm password', validators=[Required()])

    submit = SubmitField('Submit')


class EditProfileForm(Form): # 资料编辑器
    name = StringField('Real name', validators=[Length(0, 64)])
    location = StringField('Location', validators=[Length(0, 64)])
    about_me = TextAreaField('About me')
    submit = SubmitField('Submit')


class EditProfileAdminForm(Form):
    email = StringField('Email', validators=[Required(), Length(1, 64),
                                                Email()])
    username = StringField('Username', validators=[
        Required(), Length(1, 64), Regexp('^[A-Za-z][A-Za-z0-9_.]*$', 0,
                                          'Usernames must have only letters, numbers, dots or underscroes')])
    confirmed = BooleanField('Confirmed')
    role = SelectField('Role', coerce=int)
    name = StringField('Real name', validators=[Length(0, 64)])
    location = StringField('Location', validators=[Length(0, 64)])
    about_me = TextAreaField('About me')
    submit = SubmitField('Submit')

    def __init__(self, user, *args, **kwargs):
        super(EditProfileAdminForm, self).__init__(*args, **kwargs)
        self.role.choices = [(role.id, role.name)
                for role in Role.query.order_by(Role.name).all()]
        self.user = user

    def validate_eamil(self, field):
        if field.data != self.user.eamil and \
                User.query.filter_by(email=field.data).first():
            raise ValidationError('Email already registered.')

    def validate_username(self, field):
        if field.data != self.user.username and \
                User.query.filter_by(username=field.data).first():
            raise ValidationError('Username already in use.')


class PostForm(Form):
    body = TextAreaField('What\'s on your mind', validators=[Required()])
    submit = SubmitField('Submit')
