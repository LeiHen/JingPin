/* To avoid CSS expressions while still supporting IE 7 and IE 6, use this script */
/* The script tag referring to this file must be placed before the ending body tag. */

/* Use conditional comments in order to target IE 7 and older:
	<!--[if lt IE 8]><!-->
	<script src="ie7/ie7.js"></script>
	<!--<![endif]-->
*/

(function() {
	function addIcon(el, entity) {
		var html = el.innerHTML;
		el.innerHTML = '<span style="font-family: \'iconfont\'">' + entity + '</span>' + html;
	}
	var icons = {
		'icon_arrows_t': '&#xe600;',
		'icon_arrows_r': '&#xe601;',
		'icon_arrows_b': '&#xe602;',
		'icon_arrows_l': '&#xe604;',
		'icon_circle_arrow_l': '&#xe609;',
		'icon_circle_arrow_b': '&#xe60a;',
		'icon_circle_arrow_r': '&#xe60b;',
		'icon_circle_arrow_t': '&#xe60c;',
		'icon_instagram': '&#xe603;',
		'icon_pinterest': '&#xe605;',
		'icon_youtube': '&#xe606;',
		'icon_weibo': '&#xe607;',
		'icon_twitter': '&#xe608;',
		'icon_qr': '&#xe60d;',
		'0': 0
		},
		els = document.getElementsByTagName('*'),
		i, c, el;
	for (i = 0; ; i += 1) {
		el = els[i];
		if(!el) {
			break;
		}
		c = el.className;
		c = c.match(/icon_[^\s'"]+/);
		if (c && icons[c[0]]) {
			addIcon(el, icons[c[0]]);
		}
	}
}());
