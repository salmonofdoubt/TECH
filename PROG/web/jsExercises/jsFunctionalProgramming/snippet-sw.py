
def a(l, i):
    def aa(x):
        l[i] = x
    return aa


def b(x,y):
    return lambda *args: x(y(*args))


def c(fn):
    return lambda arg: lambda *args: fn(arg,*args)


def g(iterable, fn):
    return (fn(i, x) for i, x in enumerate(iterable))


def foo(l, f):
    a_ = c(a)(l)
    g_ = c(g)(l)
    bar = lambda i, x: b(a_(i), f)(x)
    for i in g_(bar):
        pass


