// basic HTTP server with an export
var http = require("http"); // require the node HTTP module

function onRequest(request, response)
{
  console.log("Request received.");
  response.writeHead(200,
  {
    "Content-Type": "text/plain"
  }); // set HTTP response header
  response.write("Hello World"); // write content into HTTP request
  response.end(); // finishes the response
}

http.createServer(onRequest).listen(8888);

console.log("Server has started.");