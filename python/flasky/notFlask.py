class notFlask():
    def route(self, route_str):
        def decorator(f):
            return f
        return decorator

app = notFlask()

@app.route("/")
def hello():
    print "Hello, World!"

hello()
