from datetime import datetime
from flask import render_template, session, redirect, url_for
from flask.ext.moment import Moment
from flask.ext.login import login_required

from . import main
from .forms import NameForm, EmailForm
from .. import db
from ..models import User

@main.route('/', methods=['GET', 'POST'])
def index():
    form = NameForm()
    if form.validate_on_submit():
        user = User.query.filter_by(username=form.name.data).first()
        if user is None:
            user = User(username = form.name.data)
            db.session.add(user)
            session['known'] = False
        else:
            session['known'] = True
        session['name'] = form.name.data
        form.name.data = ''
        return redirect(url_for('.index'))
    return render_template('index.html',
            form=form, name=session.get('name'),
            known=session.get('known', False),
            current_time=datetime.utcnow())

@main.route('/user/<username>')
def user(username):
    user = User.query.filter_by(username=username).first_or_404()
    return render_template('user.html', user=user, username=username)

@main.route('/base/')
def base():
    return render_template('base.html')

@main.route('/time/')
def time():
    return render_template('time.html', time=datetime.utcnow())

@main.route('/email/', methods=['GET', 'POST'])
def email():
    email_form = EmailForm()
    return render_template('email.html', form=email_form)


@main.route('/secret')
@login_required
def secret():
    return 'Only authenticated users are allowed!'


