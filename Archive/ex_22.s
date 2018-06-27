.name "龜亀龟龟龜亀龟龜亀龟龜kāngxī zìdiǎn tǐ亀龟龜亀龟龜亀龟龜亀龟龜亀龟"
.comment "just a basic living prog"
		
l2:	sti	r1,%:live,%0
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
