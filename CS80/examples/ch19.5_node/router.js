// create a router; this could also route to different applications (controllers) based on the file extension, or other information
// here, we just print the request we are routing
function route(pathname)
{
  console.log("About to route a request for " + pathname);
}

exports.route = route;