import ecflow

print("Client -> Server: delete, then load a new definition")
try:
    ci = ecflow.Client()
    ci.delete_all()  # clear out the server
    ci.load("test.def")  # load the definition into the server
    ci.begin_suite("test")  # start the suite
except RuntimeError as e:
    print("Failed:", e)
