set width (500)
set height (500)
create rectangle rect
set rect->x (50)
set rect->y (50)
set rect->height (50)
set rect->width (50)
animation rect anim1
set rect->anim1->dur (2s)
set rect->anim1->attributeName (x)
set rect->anim1->attributeType (XML)
set rect->anim1->from (-50)
set rect->anim1->to (100)
set rect->anim1->repeatCount (indefinite)
create polyline pol
set pol->points (100,100 150,25 150,75 200,0)
setAll fill (blue)
create line ll
set ll->y1 (100)
set ll->x1 (100)
set ll->x2 (75)
set ll->y2 (50)
create line ll4
create line ll3
create line ll2
export ("test.svg")