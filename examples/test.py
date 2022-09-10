import emblem


class MyApplication(emblem.Application):
    def __init__(self):
        super().__init__()


if __name__ == "__main__":
    app = MyApplication()
    app.run()
