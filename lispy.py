# coding: utf-8
from __future__ import division

Symbol = str
# 字符串函数 把收到的所有数据类型都变成字符串

class Env(dict):
    def __init__(self, parms=(), args=(), outer=None):
        self.update(zip(parms,args))
        self.outer = outer
    def find(self, var):
        "用来为一个变量查找正确的环境"
        return self if var in self else self.outer.find(var)




def add_globals(env):
    "添加 20 种 常用的过程"
    import math, operator as op
    env.update(vars(math)) # 数学相关
    env.update(
        {'+':op.add, '-':op.sub, '*':op.mul, '/':op.div, 'not':op.not_,
         '>':op.gt, '<':op.lt, '>=':op.ge, '<=':op.le, '=':op.eq,
         'equal?':op.eq, 'eq?':op.is_, 'length':len, 'cons':lambda x,y:[x]+y,
         'car':lambda x:x[0], 'cdr':lambda x:x[1:], 'append':op.add,
         'list':lambda *x:list(x), 'list?':lambda x:isa(x,list),
         'null>':lambda x:x==[], 'symbol?':lambda x: isa(x,Symbol)})
    return env

global_env = add_globals(Env())

isa = isinstance



def eval(x, env=global_env):
    "评估一个表达式的环境."
    if isa(x, Symbol): # 变量引用
        return env.find(x)[x]
    elif not isa(x, list): # 字面常量
        return x
    elif x[0] == 'quote':
        (_, exp) = x
        return exp
    elif x[0] == 'if':
        (_, test, conseq, alt) = x
        return eval((conseq if eval(test, env) else alt), env)
    elif x[0] == 'set!':
        (_, var, exp) = x
        env.find(var)[var] = eval(exp,env)
    elif x[0] == 'define':
        (_, var, exp) == x
        env[var] = eval(exp, env)
    elif x[0] == 'lambda':
        (_, vars, exp) = x
        return lambda *args: eval(exp, Env(vars, args, env))
    elif x[0] == 'begin':
        for exp in x[1:]:
            val = eval(exp, env)
            return val
    else:
        exps = [eval(exp, env) for exp in x]
        proc = exps.pop(0)
        return proc(*exps)





def read(s):
    "读入 scheme字符串表达式"
    return read_from(tokenize(s))

parse = read

def tokenize(s):
    return s.replace('(',' ( ').replace(')',' ) ').split()


def read_from(tokens):
    if len(tokens) == 0:
        raise SyntaxError('unexpected EOF while reading')
    token = tokens.pop(0)
    if '(' == token:
        L = []
        while tokens[0] != ')': # 当碰见）右括号的时候 结束循环
            L.append(read_from(tokens))
            tokens.pop(0) # pop off
            return L
    elif ')' == token:
        raise SyntaxError('unexpected )')
    else:
        return atom(token)


def atom(token):
    try: return int(token)
    except ValueError:
        try: return float(token)
        except ValueError:
            return Symbol(token)


def to_string(exp):
    return '('+' '.join(map(to_string, exp))+')' if isa(exp, list) else str(exp)


def repl(prompt='lis.py> '):
    while True:
        val = eval(parse(raw_input(prompt)))
        if val is not None: print to_string(val)































