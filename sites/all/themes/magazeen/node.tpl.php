<?php
// $Id: node.tpl.php,v 1.7.4.1 2010/05/19 19:11:31 sheenad Exp $
?>

<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">

  <div class="node-title-wrapper clearfix">
    <?php if ($page == 0): ?>
    <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <?php endif; ?>

    <?php if ($submitted): ?>
      <div class="meta">
        <span class="submitted"><?php print $submitted ?></span>
      </div>
    <?php endif; ?>
  </div>

  <div class="inner">
    <div class="node-inner-padding">
    <?php if ($node_top && !$teaser): ?>
      <div id="node-top" class="node-top row nested">
        <div id="node-top-inner" class="node-top-inner inner">
          <?php print $node_top; ?>
        </div><!-- /node-top-inner -->
      </div><!-- /node-top -->
      <?php endif; ?>

      <div class="content clearfix">
        <?php print $picture ?>
        <?php print $content ?>
      </div>

      <?php if ($terms): ?>
      <div class="terms">
        <?php print $terms; ?>
      </div>
      <?php endif;?>
    </div><!-- /node-inner-padding -->

    <?php if ($links): ?>
    <div class="links clearfix">
      <?php print $links; ?>
    </div>
    <?php endif; ?>
  </div><!-- /inner -->

  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom" class="node-bottom row nested">
    <div id="node-bottom-inner" class="node-bottom-inner inner">
      <?php print $node_bottom; ?>
    </div><!-- /node-bottom-inner -->
  </div><!-- /node-bottom -->
  <?php endif; ?>
</div><!-- /node-<?php print $node->nid; ?> -->
