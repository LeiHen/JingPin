<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?>
<html>
<head>
<meta http-equiv='Content-Type' content='text/html; charset=utf-8'>
<title>友情链接管理</title>
<link href='img/base.css' rel='stylesheet' type='text/css'>
<script language='javascript'>
function Sel(stype)
{
	  for(var i=0;i < document.getElementsByName('aids').length;i++)
	  {
		  if(stype=='all') document.getElementsByName('aids')[i].checked=true;
		  else document.getElementsByName('aids')[i].checked=false;
	  }
}
function checkSubmit()
{
	var str = '';
	for(var i=0;i < document.getElementsByName('aids').length;i++)
	{
		  if(document.getElementsByName('aids')[i].checked){
		  	if(str=='') str += document.getElementsByName('aids')[i].value;
		  	else str += ',' + document.getElementsByName('aids')[i].value;
		  }
	}
	if(str=='')
	{
		alert('你沒選擇任何內容！');
		return false;
	}
	else
	{
		location="friendlink_edit.php?aids="+str+"&dopost=delall";
	}
}
</script>
</head>
<body background='img/allbg.gif' leftmargin='8' topmargin='8'>
<table width="98%" border="0" align="center" cellpadding="3" cellspacing="1" bgcolor="#D1DDAA">
  <form name='form1' method='post' action='flash_edit.php' onSubmit='return checkSubmit();'>
  	<input type='hidden' name='dopost' value='delall'/>
  	<input type='hidden' name='allid' value=''/>
  <tr>
    <td height="28" background="img/tbg.gif" colspan="7">
  <div style="float:left"><span class="lbox">幻灯广告管理</span></div>
	<div style="float:right;padding-right:6px;">
		[<a href="flash_add.php"><u>增加幻灯图片</u></a>]  </div>  </td>
</tr>
  <tr align="center" bgcolor="#F9FCEF" height="26">
          <td width="6%">选择</td>
          <td width="23%">幻灯名称</td>
      <td width="12%">幻灯图片</td>
      <td>时间</td>
      <td width="8%">状态</td>
          <td width="8%">顺序</td>
          <td width="15%">管理</td>
        </tr>
        <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
        <tr align="center" bgcolor="#FFFFFF" height="26" onMouseMove="javascript:this.bgColor='#FCFDEE';"
        	 onMouseOut="javascript:this.bgColor='#FFFFFF';">
          <td><input type='checkbox' name='aids' value='<?php echo $fields['id']; ?>' class='np'></td>
          <td><a href="<?php echo $fields['url']; ?>" target='_blank'><?php echo $fields['webname']; ?></a></td>
          <td><a href="<?php echo $fields['url']; ?>" target='_blank'><?php echo GetPic($fields['pic']); ?></a></td>
          <td><?php echo MyDate('Y-m-d',$fields['dtime']); ?></td>
          <td><?php echo GetSta($fields['ischeck']); ?></td>
          <td><?php echo $fields['sortrank']; ?></td>
          <td><a href='flash_edit.php?id=<?php echo $fields['id']; ?>&dopost=getedit'>[更改]</a> <a href='flash_edit.php?id=<?php echo $fields['id']; ?>&dopost=delete'>[删除]</a> </td>
        </tr>
		<?php
}
}?>
     <tr bgcolor="#FDFEEF" height="28">
      <td colspan="7">
      	　
        <a href='#' onclick='Sel("all")' class='np coolbg'>[全选]</a>
      	<a href='#' onclick='Sel("none")' class='np coolbg'>[取消]</a>
      	<a href='#' onclick='checkSubmit()' class='np coolbg'>批量刪除</a>      </td>
     </tr>
     <tr align="center" bgcolor="#F9FCEF" height="28">
      <td colspan="7">
      	<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '6';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
      </td>
     </tr>
    </form>
   </table>
</td>
</tr>
</table>
</body>
</html>