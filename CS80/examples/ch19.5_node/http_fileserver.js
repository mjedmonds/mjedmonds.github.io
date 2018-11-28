var http = require('http');
var url = require('url');
var fs = require('fs');

function start(route)
{
  function onRequest(request, response)
  {
    // look for file in current directory
    var filename = "." + url.parse(request.url).pathname;
    console.log("Request for " + filename + " received.");
    fs.readFile(filename, function(err, data)
    {
      // error getting the file, return a 404
      if (err)
      {
        response.writeHead(404,
        {
          'Content-Type': 'text/html'
        });
        return response.end("404 Not Found");
      }
      // successfully retrieved file
      response.writeHead(200,
      {
        'Content-Type': 'text/html'
      });
      // write the file's data into the response
      response.write(data);
      return response.end();
    });
  }
  http.createServer(onRequest).listen(8888);
  console.log("Server has started.");
}

exports.start = start