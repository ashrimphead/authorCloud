Development of this new version of uc_canadapost was sponsored by
PnwGardenSupply.com / MyGreenPlanet.com

The differences between this version and the previously posted versions are listed below.  The main feature of this version is the automatic division of order products into packages of 30kg or less.  30kg is the Canada Post weight limit for a package.  This version will calculate how many packages need to be sent, calculate the cost of shipping each package, and display the total number of packages and the total shipping cost to the customer.


Modifications to the uc_canadapost.module posted at the top of this thread
include:

Added uc_canadapost_package_products() which limits the weight of a package to 30kg and returns an array of packages and their weights.

Modified uc_canadapost_make_request() to accept $packages (an array of packages to be shipped) as an argument instead of $products (an array of products to be shipped.

Modified uc_canadapost_quote() to call the packaging function, get a quote for each package, and calculate the order shipping quote as the sum the package shipping quotes.

Added Workflow-ng configuration hook uc_canadapost_configuration() so Workflow-ng can be used to set conditions for uc_canadapost. (For example, free shipping on orders over $x, etc.).  This makes uc_canadapost behave like all the other shipping modules.


Added code to strip spaces from postal codes.

Changed some formatting to conform to Drupal coding standards.  Changed some
formatting for readability.

Added comments.

