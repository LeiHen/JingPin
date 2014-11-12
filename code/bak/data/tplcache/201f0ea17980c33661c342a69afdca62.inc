<li>
      				[field:array runphp='yes']@me = (empty(@me['litpic']) ? "" : "<a href='{@me['arcurl']}' class='preview'><img src='{@me['litpic']}'/></a>"); [/field:array]
					<a href="[field:arcurl/]" class="title">[field:title/]</a>
					<span class="info">
						<small>日期：</small>[field:pubdate function="GetDateTimeMK(@me)"/]
						<small>价格：</small>[field:trueprice/]
						<small>品牌：</small>[field:brand/]
						<small>人气：</small>[field:click/]
					</span>
					<p class="intro">
						[field:description/]...
					</p>
				</li>
	
            <li class="list">
               
               <div class="txt_wrap">
                   <p class="info">[field:description/]</p>
                   <a href="[field:arcurl/]" class="btn ext_btn_capital">
                        more
                        <span class="line_t"></span>
                        <span class="line_r"></span>
                        <span class="line_b"></span>
                        <span class="line_l"></span>
                   </a>
               </div>
               
               <div class="img_wrap">
                   <img src="[field:picname/]" class="img" alt="[field:title/]" title="[field:title/]">
                   <h2 class="name">[field:title/]</h2>
                   <span class="type">strass</span>
               </div>
            </li>