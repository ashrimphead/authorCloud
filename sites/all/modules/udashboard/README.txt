/* $Id: README.txt,v 1.1 2009/05/03 07:56:56 lelizondob Exp $ */

User Dashboard (udashboard) creates a pseudo administration interface
for users who are not administrators.

This module it's trying to solve a common problem when you give control
of the site to users who aren´t drupal experts. From a single UI it's
possible to administer the most common tasks of the site like having a
tracker page, administer comments, administer users and creating
content.

I created this module because it's so much easier to give the site
manager just one single url to administer the common areas of the site
than teaching him/her how to do every task independently with different
urls. Also, the Drupal's admin page sometimes can be confusing.

Currently, it's possible to define 4 pages inside the UI, all of them
with custom help messages.

1. Tracker and Welcome Page

An admin can set the welcome page to use tracker2 or a custom view.
Currently the site does not support tracker. The reason it's tracker2
it's faster than tracker, but patches are welcome.


2. Comments page
It's possible to load the usual comments administration page or a
custom view to show comments.

3. Create content page
The node/add page sometimes it's confusing for some users. This module
will let the admin add a help message to the node/add page and configure
the page to show or hide the descriptions. Also, having the "create
page" link in the same UI makes this task simpler.

If you have the Popups module installed, you can also make use of it.


4. Users page
The users page loads the usual users page.

This module it's not complete, it's being used in a production site,
but there's functionality that will be added soon, expect changes, maybe
a different version. It doesn't create or alter tables so it's safe to
use it. I recommend to try it and know it before you use it on a production
site.

Currently, it doesn't create views on install but they're included in
the views folder, there's also a css file you can use. There's also some
work to do with the comments view. If you want to use the views provided
by this module, you'll have to import them and copy the css and tpl.php
files to your theme's folder and then let views know you're theming the
view. If you change your view name, you'll have to rename the file.

There's also the possibility to add any view to the UI, there's more on
this at the end of the udashboard.tabs file.

IMPORTANT: If you change the Comments settings, you have to clear the cache.

There's so much work to do with this module, patches are welcome, I'll be
creating a version 2.x soon easier to configure.

Credits
-------------------------------
Author: Luis Elizondo (lelizondob)
lelizondo at gmail [dot] com

Note from the Author
I want to give lots of credit to 'douggreen', the autor of
http://drupal.org/project/createcontentblock, his code made my life easier
when recreating the "Create Content" page.