var server = require("./http_fileserver");
var router = require("./router");

server.start(router.route);