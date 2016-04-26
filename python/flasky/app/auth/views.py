# coding: utf-8
from flask import render_template
from flask import redirect, request, url_for, flash
from flask.ext.login import login_user, login_required
from flask.ext.login import UserMixin

from . import auth
from ..models import User
from .forms import LoginForm

#@auth.route('/login')
#def login():
#    return render_template('auth/login.html')

@auth.route('/login', methods=['GET','POST']) # auth 是当前文件夹的名字
def login():
    form = LoginForm()
    if form.validate_on_submit():
        user = User.query.filter_by(email=form.email.data).first()
        if user is not None and user.verify_password(form.password.data):
            login_user(user, form.remember_me.data)
            return redirect(request.args.get('next') or url_for('main.index'))
        flash('Invalid username or password.')
    return render_template('auth/login.html', form=form)

@auth.route('/logut')
@login_required
def logout():
    logout_user()
    flash('You have been logged out.')
    return redirect(url_for('main.index'))

@auto.route('/register', methods=['GET', 'POST'])
def register():
    form = RegistrationForm()
    if form.validate_on_submit():
        user = User(email=form.email.data,
                    username=form.username.data,
                    password=form.password.data)
        db.session.add(user)
        flash('You can now login.')
        return redirect(url_for('auth.login'))
    return render_template('auth/register.html', form=form)
