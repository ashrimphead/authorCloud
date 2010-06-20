<?php
// $Id: description.tpl.php,v 1.1.2.1 2009/07/19 16:24:04 starnox Exp $

/**
 * @file
 * This template outputs the description field.
 *
 * Variables:
 * - $title
 * - $artist
 * - $album
 * - $year
 * - $track
 * - $genre
 */
?>
<?php print $title .' '. t('by') .' '. $artist; ?>