# Braino
When sent a message, Braino looks up that message in a database and responds with a past response.
The database has been seeded with my facebook chat history.

Essentially I just map a message to the very next message sent, regardless of user.
Unfortunately, because of group chats and double-messaging, many of his replies don't make sense.

---

## Dependencies
* [MySQLConnector-C++](http://dev.mysql.com/doc/connector-cpp/en/)

---

## Resources

### MySQL
* [One to many](http://stackoverflow.com/q/12402422/5415895)
* [Insert if not exists](http://stackoverflow.com/a/3164595/5415895)