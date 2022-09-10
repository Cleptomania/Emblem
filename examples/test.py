import emblem
import emblem.log as log


class MyApplication(emblem.Application):
    def __init__(self):
        super().__init__()


if __name__ == "__main__":
    app = MyApplication()
    log.trace("This is a trace log")
    log.info("This is an info log")
    log.warn("This is a warning log")
    log.error("This is an error log")
    app.run()
