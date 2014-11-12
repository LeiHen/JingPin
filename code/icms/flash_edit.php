<?php
require_once(dirname(__FILE__)."/config.php");
CheckPurview('plus_幻灯广告模块');
$ENV_GOBACK_URL = empty($_COOKIE['ENV_GOBACK_URL']) ? 'flash_main.php' : $_COOKIE['ENV_GOBACK_URL'];
if(empty($dopost))
{
	$dopost = "";
}
if(isset($allid))
{
	$aids = explode(',',$allid);
	if(count($aids)==1)
	{
		$id = $aids[0];
		$dopost = "delete";
	}
}
if($dopost=="delete")
{
	$id = ereg_replace("[^0-9]","",$id);
	$dsql->ExecuteNoneQuery("Delete From `#@__flash` where id='$id'");
	ShowMsg("成功删除一个幻灯图片！",$ENV_GOBACK_URL);
	exit();
}
else if($dopost=="delall")
{
	$aids = explode(',',$aids);
	if(isset($aids) && is_array($aids))
	{
		foreach($aids as $aid)
		{
			$aid = ereg_replace("[^0-9]","",$aid);
			$dsql->ExecuteNoneQuery("Delete From `#@__flash` where id='$aid'");
		}
		ShowMsg("成功删除指定幻灯图片！",$ENV_GOBACK_URL);
		exit();
	}
	else
	{
		ShowMsg("你没选定任何幻灯图片！",$ENV_GOBACK_URL);
		exit();
	}
}
else if($dopost=="saveedit")
{	
	$dtime = time();
	if(is_uploaded_file($flashimg))
	{
		$names = split("\.",$flashimg_name);
		$shortname = ".".$names[count($names)-1];
		if(!eregi("(jpg|gif|png)$",$shortname))
		{
			$shortname = '.gif';
		}
		$filename = MyDate("ymdHis",time()).mt_rand(1000,9999).$shortname;
		$imgurl = $cfg_medias_dir."/flash";
		if(!is_dir($cfg_basedir.$imgurl))
		{
			MkdirAll($cfg_basedir.$imgurl,$cfg_dir_purview);
			CloseFtp();
		}
		$imgurl = $imgurl."/".$filename;
		move_uploaded_file($flashimg,$cfg_basedir.$imgurl) or die("复制文件到:".$cfg_basedir.$imgurl."失败");
		@unlink($flashimg);
	}
	else
	{
		$imgurl = $flash;
	}
	$id = ereg_replace("[^0-9]","",$id);
	$query = "Update `#@__flash` set sortrank='$sortrank',url='$url',webname='$webname',pic='$imgurl',msg='$msg',ischeck='$ischeck' where id='$id' ";
	$dsql->ExecuteNoneQuery($query);
	ShowMsg("成功更改一个幻灯图片！",$ENV_GOBACK_URL);
	exit();
}
$myFlash = $dsql->GetOne("Select * From #@__flash where id=$id");
include DedeInclude('templets/flash_edit.htm');

?>