# coding: utf-8
import os
basedir = os.path.abspath(os.path.dirname(__file__))

class Config:
    SECRET_KEY = os.environ.get('SECRET_KEY') or 'hard to guess string'
    SQLALCHEMY_COMMIT_ON_TEARDOWN = True
    FLASKY_MAIL_SUBJECT_PREFIX = '[FLASKY]'
    FLASKY_MAIL_SENDER = 'hongjunjie2012 <hongjunjie2012@yeah.net>'
    FLASKY_ADMIN = 'hongjunjie2012'

    @staticmethod
    def init_app(app):
        pass

class DevelopmentConfig(Config): # 开发模式的配置
    DEBUG = True
    MAIL_SERVER = 'smtp.yeah.net'
    MAIL_PORT = 25
    MAIL_USE_TLS = True
    MAIL_USERNAME = 'hongjunjie2012@yeah.net'
    MAIL_PASSWORD = 'shadyxv0418'
    SQLALCHEMY_DATABASE_URI = os.environ.get('DEV_DATABASE_URL') or\
            'sqlite:///' + os.path.join(basedir, 'database-dev.sqlite')

class TestingConfig(Config): # 测试配置
    TESTING = True
    SQLALCHEMY_DATABASE_URI = os.environ.get('TEST_DATABASE_URL') or\
            'sqlite:///' + os.path.join(basedir, 'database-test.sqlite')

class ProductionConfig(Config):# 生产模式配置
    SQLALCHEMY_DATABASE_URI = os.environ.get('DATABASE_URL') or\
            'sqlite:///' + os.path.join(basedir, 'database.sqlite')

config = {
        'development': DevelopmentConfig,
        'testing': TestingConfig,
        'production': ProductionConfig,

        'default': DevelopmentConfig
}
