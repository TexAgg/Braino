# Braino
When sent a message, Braino looks up that message in a database and responds with a past response.
The database has been seeded with my [Facebook chat history](https://www.facebook.com/help/212802592074644?helpref=uf_permalink).
Essentially I just map a message to the very next message sent, regardless of user.
Unfortunately, because of group chats and double-messaging, many of his replies don't make sense.

---

## Dependencies
* [MySQLConnector-C++](http://dev.mysql.com/doc/connector-cpp/en/)
* Boost