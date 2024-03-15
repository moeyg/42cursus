#ifndef __COMMANDRESPONSES_HPP__
#define __COMMANDRESPONSES_HPP__

#define RPL_WELCOME             ":InternetRelayChat.net 001"
#define RPL_YOURHOST            ":InternetRelayChat.net 002 Your host is InternetRelayChat.net, running version v1.0\r\n"
#define RPL_CREATED             ":InternetRelayChat.net 003 This server was created today\r\n"
#define RPL_MYINFO              ":InternetRelayChat.net 004 InternetRelayChat.net v1.0 none\r\n"

#define RPL_BOUNCE              005

#define RPL_TRACELINK           200
#define RPL_TRACECONNECTING     201
#define RPL_TRACEHANDSHAKE      202
#define RPL_TRACEUNKNOWN        203
#define RPL_TRACEOPERATOR       204
#define RPL_TRACEUSER           205
#define RPL_TRACESERVER         206
#define RPL_TRACESERVICE        207
#define RPL_TRACENEWTYPE        208
#define RPL_TRACECLASS          209

#define RPL_TRACERECONNECT      210
#define RPL_STATSLINKINFO       211
#define RPL_STATSCOMMANDS       212
#define RPL_STATSCLINE          213
#define RPL_STATSNLINE          214
#define RPL_STATSILINE          215
#define RPL_STATSKLINE          216
#define RPL_STATSQLINE          217
#define RPL_STATSYLINE          218
#define RPL_ENDOFSTATS          219

#define RPL_UMODEIS             221

#define RPL_SERVICEINFO         231
#define RPL_ENDOFSERVICES       232
#define RPL_SERVICE             233
#define RPL_SERVLIST            234
#define RPL_SERVLISTEND         235

#define RPL_STATSVLINE          240
#define RPL_STATSLLINE          241
#define RPL_STATSUPTIME         242
#define RPL_STATSOLINE          243
#define RPL_STATSHLINE          244
#define RPL_STATSSLINE          244
#define RPL_STATSPING           246
#define RPL_STATSBLINE          247

#define RPL_STATSDLINE          250
#define RPL_LUSERCLIENT         251
#define RPL_LUSEROP             252
#define RPL_LUSERUNKNOWN        253
#define RPL_LUSERCHANNELS       254
#define RPL_LUSERME             255
#define RPL_ADMINME             256
#define RPL_ADMINLOC1           257
#define RPL_ADMINLOC2           258
#define RPL_ADMINEMAIL          259

#define RPL_TRACELOG            261
#define RPL_TRACEEND            262
#define RPL_TRYAGAIN            263

#define RPL_NONE                300
#define RPL_AWAY                301
#define RPL_USERHOST            302
#define RPL_ISON                303
#define RPL_UNAWAY              305
#define RPL_NOWAWAY             306

#define RPL_WHOISUSER           311
#define RPL_WHOISSERVER         312
#define RPL_WHOISOPERATOR       313
#define RPL_WHOWASUSER          314
#define RPL_ENDOFWHO            315
#define RPL_WHOISCHANOP         316
#define RPL_WHOISIDLE           317
#define RPL_ENDOFWHOIS          318
#define RPL_WHOISCHANNELS       319

#define RPL_LISTSTART           321
#define RPL_LIST                322
#define RPL_LISTEND             323
#define RPL_CHANNELMODEIS       324
#define RPL_UNIQOPIS            325

#define RPL_NOTOPIC             331
#define RPL_TOPIC               332

#define RPL_INVITING            341
#define RPL_SUMMONING           342
#define RPL_INVITELIST          346
#define RPL_ENDOFINVITELIST     347
#define RPL_EXCEPTLIST          348
#define RPL_ENDOFEXCEPTLIST     349

#define RPL_VERSION             351
#define RPL_WHOREPLY            352

#define RPL_KILLDONE            361
#define RPL_CLOSING             362
#define RPL_CLOSEEND            363
#define RPL_LINKS               364
#define RPL_ENDOFLINKS          365
#define RPL_BANLIST             367
#define RPL_ENDOFBANLIST        368
#define RPL_ENDOFWHOWAS         369

#define RPL_INFO                371
#define RPL_MOTD                372
#define RPL_INFOSTART           373
#define RPL_ENDOFINFO           374
#define RPL_MOTDSTART           375
#define RPL_ENDOFMOTD           376

#define RPL_YOUREOPER           381
#define RPL_REHASHING           382
#define RPL_YOURESERVICE        383
#define RPL_MYPORTIS            384

#define RPL_TIME                391
#define RPL_USERSSTART          392
#define RPL_USERS               393
#define RPL_ENDOFUSERS          394
#define RPL_NOUSERS             395

#define RPL_NAMREPLY            ":InternetRelayChat.net 353 "
#define RPL_ENDOFNAMES          ":InternetRelayChat.net 366 "

#define ERR_NOSUCHNICK          ":InternetRelayChat.net 401 "
#define ERR_NOSUCHSERVER        ":InternetRelayChat.net 402 "
#define ERR_NOSUCHCHANNEL       ":InternetRelayChat.net 403 "
#define ERR_CANNOTSENDTOCHAN    ":InternetRelayChat.net 404 "
#define ERR_TOOMANYCHANNELS     ":InternetRelayChat.net 405 "
#define ERR_WASNOSUCHNICK       ":InternetRelayChat.net 406 "
#define ERR_TOOMANYTARGETS      ":InternetRelayChat.net 407 "
#define ERR_NOSUCHSERVICE       ":InternetRelayChat.net 408 "
#define ERR_NOORIGIN            ":InternetRelayChat.net 409 "

#define ERR_NORECIPIENT         ":InternetRelayChat.net 411 "
#define ERR_NOTEXTTOSEND        ":InternetRelayChat.net 412 "
#define ERR_NOTOPLEVEL          ":InternetRelayChat.net 413 "
#define ERR_WILDTOPLEVEL        ":InternetRelayChat.net 414 "
#define ERR_BADMASK             ":InternetRelayChat.net 415 "

#define ERR_UNKNOWNCOMMAND      ":InternetRelayChat.net 421 "
#define ERR_NOMOTD              ":InternetRelayChat.net 422 "
#define ERR_NOADMININFO         ":InternetRelayChat.net 423 "
#define ERR_FILEERROR           ":InternetRelayChat.net 424 "

#define ERR_NONICKNAMEGIVEN     ":InternetRelayChat.net 431 :No nickname given\r\n"
#define ERR_ERRONEUSNICKNAME    ":InternetRelayChat.net 432 "
#define ERR_NICKNAMEINUSE       ":InternetRelayChat.net 433 "
#define ERR_NICKCOLLISION       ":InternetRelayChat.net 436 "
#define ERR_UNAVAILRESOURCE     ":InternetRelayChat.net 437 "

#define ERR_USERNOTINCHANNEL    ":InternetRelayChat.net 441 "
#define ERR_NOTONCHANNEL        ":InternetRelayChat.net 442 "
#define ERR_USERONCHANNEL       ":InternetRelayChat.net 443 "
#define ERR_NOLOGIN             ":InternetRelayChat.net 444 "
#define ERR_SUMMONDISABLED      ":InternetRelayChat.net 445 "
#define ERR_USERSDISABLED       ":InternetRelayChat.net 446 "

#define ERR_NOTREGISTERED       ":InternetRelayChat.net 451 "

#define ERR_NEEDMOREPARAMS      ":InternetRelayChat.net 461 "
#define ERR_ALREADYREGISTRED    ":InternetRelayChat.net 462 :Unauthorized command (already registered)\r\n"
#define ERR_NOPERMFORHOST       ":InternetRelayChat.net 463 "
#define ERR_PASSWDMISMATCH      ":InternetRelayChat.net 464 :Password incorrect\r\n"
#define ERR_YOUREBANNEDCREEP    ":InternetRelayChat.net 465 "
#define ERR_YOUWILLBEBANNED     ":InternetRelayChat.net 466 "
#define ERR_KEYSET              ":InternetRelayChat.net 467 "

#define ERR_CHANNELISFULL       ":InternetRelayChat.net 471 "
#define ERR_UNKNOWNMODE         ":InternetRelayChat.net 472 "
#define ERR_INVITEONLYCHAN      ":InternetRelayChat.net 473 "
#define ERR_BANNEDFROMCHAN      ":InternetRelayChat.net 474 "
#define ERR_BADCHANNELKEY       ":InternetRelayChat.net 475 "
#define ERR_BADCHANMASK         ":InternetRelayChat.net 476 "
#define ERR_NOCHANMODES         ":InternetRelayChat.net 477 "
#define ERR_BANLISTFULL         ":InternetRelayChat.net 478 "

#define ERR_NOPRIVILEGES        ":InternetRelayChat.net 481 "
#define ERR_CHANOPRIVSNEEDED    ":InternetRelayChat.net 482 "
#define ERR_CANTKILLSERVER      ":InternetRelayChat.net 483 "
#define ERR_RESTRICTED          ":InternetRelayChat.net 484 "
#define ERR_UNIQOPPRIVSNEEDED   ":InternetRelayChat.net 485 "

#define ERR_NOOPERHOST          ":InternetRelayChat.net 491 "
#define ERR_NOSERVICEHOST       ":InternetRelayChat.net 492 "

#define ERR_UMODEUNKNOWNFLAG    ":InternetRelayChat.net 501 "
#define ERR_USERSDONTMATCH      ":InternetRelayChat.net 502 "

#endif
