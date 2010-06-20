<?php
// $Id: vd.tpl.php,v 1.1.2.2 2010/04/02 13:29:08 swentel Exp $

/**
 * This template is optimized for use with the Views displays module.
 * It's a replacement for views-view.tpl.php
 */
?>

<div class="view view-<?php print $css_name; ?> view-id-<?php print $name; ?> view-display-id-<?php print $display_id; ?> view-dom-id-<?php print $dom_id; ?>">

<?php print $views_content; ?>

</div>

