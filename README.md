# Braino
When sent a message, Braino looks up that message in a database and responds with a past response.
The database has been seeded with my [Facebook](https://www.facebook.com/help/212802592074644?helpref=uf_permalink) and [Telegram](https://github.com/pigpagnet/save-telegram-chat-history) chat history,
using the scripts [here](#data-extraction).
Essentially I just map a message to the very next message sent, regardless of user.
Unfortunately, because of group chats and double-messaging, many of his replies don't make sense.

---

## Dependencies
* [MySQLConnector-C++](http://dev.mysql.com/doc/connector-cpp/en/)
* Boost

---

## Resources

### Data extraction
* [Facebook](https://www.dropbox.com/s/bry6cw2zzfrde9q/fb_extract.py?dl=0)
* [Telegram](https://www.dropbox.com/s/svu1l1somzz38r5/tg_extract.py?dl=0)