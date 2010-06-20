/* $Id: README.txt,v 1.1.2.1 2010/05/19 19:37:09 sheenad Exp $ */

-- SUMMARY --

Magazeen is an advanced Drupal theme, based on the free wordpress theme designed by WeFunction Design Agency and distributed on Smashing Magazine in Februrary 2009.

This theme is a subtheme of the Fusion Core base theme.  Magazeen + Fusion is a little different from most Drupal themes you may be used to.  Positioning and block styles are controlled through Drupal's UI via the Skinr module, which is required if you want to actually use styles.  These configurable options give Magazeen an unparalleled amount of flexibility and features.


-- REQUIREMENTS --

Fusion Core:
  http://drupal.org/project/fusion

Skinr:
  http://drupal.org/project/skinr


-- INSTALLATION --

* Download both Magazeen and Fusion (http://drupal.org/project/fusion)

* Unpack them as usual within your themes folder.  You'll see two themes in the Fusion folder -- Fusion Core (the base theme), and Fusion Starter (a commented starter theme for creating your own subthemes)

* Enable Fusion Core and Magazeen on your themes page on example.com/admin/build/themes

* Set Magazeen as your default theme

* Download and enable the Skinr module

   - The dev snapshot is currently recommended for the most up-to-date version: http://ftp.drupal.org/files/projects/skinr-6.x-1.x-dev.tar.gz

* You may need to give your administrator role Skinr permissions on example.com/admin/user/permissions


-- CONFIGURATION --

* You can control many settings on Magazeen's theme settings page: example.com/admin/build/themes/settings/magazeen
   - Settings include menus, fixed vs fluid page width, sidebar widths, typography, search results, and administrator/developer helper features

* Superfish dropdown menus can be enabled by selecting "Expanded" next to the parent menu item in your menu configuration

* Go to your Blocks page at example.com/admin/build/block and place blocks into regions as desired, save your settings

* When hovering your cursor over blocks, a gear icon will appear -- you can use this to get to the block configuration page for that specific block

* On each block's configuration page, a "Skinr" section will appear, where you can set block styles

  NOTE: Currently Skinr's user interface is in a beta state, and only supports checkboxes at this time. Improvements are coming soon, but in the meantime, you will need to exercise some self control and not enable multiple conflicting styles at the same time. For example, only enable a single width option and a single alignment option at once. Many of the styles may also not layer well.

* Use these width and positioning options for blocks to configure your layout

* Use the style options to set up different visual styles for different blocks


-- EXAMPLES --

The following are recommended block placements/styles and other settings for Magazeen to get you started exploring what Fusion can do!

* Set the "Magazeen: Rounded Light Blue Background" style for menu blocks in your sidebar

* Try adding a menu such as your primary links block to the Footer region, and set it to use either the "Single line inline menu with separators" style for a one level menu, or "Multi-column menu with headers" style for a nested menu

* Add the user login block to the Header Top region, and set it to the "Horizontal user login" style for a sleek login form

* Add some promotional text to a block in the Preface Bottom region, and give it the "Text: large, bold callout style" for a prominent callout style

* You can also set many of these styles on Views, content types, or Panels!


-- CREDITS --

This theme has been made possible by:

* TOP NOTCH THEMES
  Theming and support by:
  http://www.topnotchthemes.com

* SMASHING MAGAZINE
  Distribution of original Wordpress Theme:
  http://www.smashingmagazine.com

* WEFUNCTION DESIGN AGENCY
  Graphic design and original Wordpress theme by:
  http://www.wefunction.com/
