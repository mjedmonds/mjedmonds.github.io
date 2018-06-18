var server = require("./http_server_router");
var router = require("./router");

server.start(router.route);