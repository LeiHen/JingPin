// JavaScript Document

/**
* @name		:
* @author	:Nice
* @dependent:
*/
function  photoSwitc(ID){
	var bigImg=$('#'+ID+' .wrap .o_hidden .img');
	var little=$('#'+ID+' .wrap .show_nav .img');
	var list=$('#'+ID+' .wrap .show_nav .list');

	var obj={
		bigImg:bigImg,
		little:little
	}
	
	list.on('mouseover',obj,function(event){
		var imgSrc=$(this).children('.img').attr('src');
		bigImg.attr('src',imgSrc);
		// console.log(bigImg);
	});
}
/* @end **/
























/**
* @name		:
* @author	:si
* @version	:
* @type		:基类
* @explain	:
* @relating	:
* @dependent:
*/

/* @end **/