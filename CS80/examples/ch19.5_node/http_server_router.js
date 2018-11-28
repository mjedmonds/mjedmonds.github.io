var http = require("http"); // require the node HTTP module
var url = require("url");

function start(route)
{
  function onRequest(request, response)
  {
    var pathname = url.parse(request.url).pathname;
    console.log("Request for " + pathname + " received.");

    route(pathname);

    response.writeHead(200,
    {
      "Content-Type": "text/plain"
    }); // set HTTP response header
    response.write("Request for " + pathname + " received."); // write content into HTTP request
    response.end(); // finishes the response
  }

  http.createServer(onRequest).listen(8888);
  console.log("Server has started.");
}

exports.start = start