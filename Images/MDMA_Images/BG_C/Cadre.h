/* GIMP RGB C-Source image dump (Cadre.c) */

static struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[60 * 30 * 2 + 1];
} gimp_image = {
  60, 30, 2,
  "J{u\265\323\234u\265J{\007sJ{\323\234\323\234\323\234\323\234\323\234\323\234"
  "\323\234\323\234\323\234\323\234\323\234\323\234\323\234\323\234\323\234"
  "\323\234\323\234\323\234\323\234\323\234\323\234\323\234\323\234\323\234"
  "\323\234\323\234\323\234\323\234\323\234\323\234\323\234\323\234\323\234"
  "\323\234\323\234\323\234\323\234\323\234\323\234\323\234\323\234\323\234"
  "\323\234\323\234\323\234\323\234J{\007sJ{u\265J{u\265$RJ{W\326<\357<\357W\326"
  "k\234\007sk\234\315\254\315\254\315\254\315\254k\234k\234k\234\315\254\315"
  "\254k\234k\234\315\254\315\254k\234k\234k\234\315\254\315\254k\234k\234\315"
  "\254\315\254k\234k\234k\234\315\254\315\254k\234k\234\315\254\315\254\315"
  "\254k\234k\234\315\254\315\254\315\254k\234\315\254\315\254\315\254k\234"
  "\315\254\315\254\315\254\007s\315\254<\357<\357W\326W\326$RJ{W\326<\357W\326"
  "W\326\351\213\351\213\315\254k\234\315\254\315\254k\234\315\254\315\254\315"
  "\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315"
  "\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315"
  "\254\315\254\315\254\315\254\315\254\315\254\315\254k\234\315\254\315\254"
  "k\234\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315"
  "\254\315\254\351\213k\234W\326W\326<\357W\326$RJ{<\357<\357k\234\007s$R\007s"
  "\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\351\213\007s\007s\007s\007s\007s\007s\007"
  "s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s\007s$R"
  "$R\007sk\234<\357<\357$R\007sW\326W\326\007s\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000$R\351\213W\326W\326$RGR\007s\007s$R\244I\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000GR$R\007s\007sGR,c\351\213\315"
  "\254\351\213\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\244Ik\234\212\244k\234,c,c\351\213\315\254\351\213\244I\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\244Ik\234\212\244k\234,c,c\351\213"
  "k\234\351\213\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\244Ik\234\351\213k\234,c,c\351\213\315\254k\234\244I\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\244Ik\234\212\244k\234,c,c\351\213"
  "\315\254k\234\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\244I\315\254\212\244k\234,c,c\351\213\351\213k\234\244I\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\244Ik\234\351\213k\234,c,c\351"
  "\213\351\213\351\213\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\244Ik\234\351\213k\234,c,c\351\213\315\254k\234\244I\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\244Ik\234\212\244k\234,c,c\351"
  "\213\315\254k\234\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\244Ik\234\212\244k\234,c,c\351\213\315\254k\234\244I\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\244Ik\234\212\244k\234,c,c\351"
  "\213\315\254k\234\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\244Ik\234\212\244k\234,c,c\351\213k\234\351\213\244I\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\244Ik\234\212\244k\234,c,c\007s"
  "\351\213k\234\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\244Ik\234\351\213J{,c,c\351\213\315\254k\234\244I\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\244I\315\254\212\244k\234,c,c\351\213"
  "\315\254k\234\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\244I\315\254\212\244k\234,c,c\351\213\315\254k\234\244I\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\244Ik\234\212\244k\234,c,c\351"
  "\213\212\244\351\213\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\244Ik\234\212\244k\234,c,c\351\213\315\254k\234\244I\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\244Ik\234\212\244k\234,cGR\007"
  "s\007sJ{\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000GRJ{\007"
  "s\007sGR\007s\315\254\315\254\007s\244I\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\244I\007s\315\254\315\254$RJ{<\357<\357k\234$R\244I$R$R$R"
  "$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R$R\000\000$R$R$R$R$R$R$R$R$R$R"
  "$R$R$R$R$R$R$R$R$R$R\244I$Rk\234<\357<\357$RJ{W\326<\357\315\254\315\254"
  "\007sk\234\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254"
  "\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254"
  "\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254"
  "\315\254\315\254\315\254\315\254\315\254\315\254k\234\315\254\315\254\315"
  "\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315\254\315"
  "\254\315\254\351\213\007s\315\254\315\254<\357W\326$RJ{W\326<\357<\357<\357"
  "k\234\351\213k\234k\234\315\254\315\254\315\254\351\213\351\213k\234\315"
  "\254\212\244k\234k\234\212\244\315\254\351\213k\234\351\213\315\254\212\244"
  "k\234k\234\212\244\212\244k\234\351\213\351\213\315\254\212\244k\234k\234"
  "\315\254\212\244\315\254\351\213\351\213\315\254\212\244k\234k\234\212\244"
  "\212\244k\234\351\213\315\254\315\254k\234\007s\315\254<\357<\357<\357W\326"
  "$RJ{W\326W\326<\357W\326\007sJ{u\265u\265u\265u\265u\265\323\234\323\234u\265"
  "u\265u\265u\265u\265u\265u\265u\265u\265\323\234u\265u\265u\265u\265u\265"
  "u\265u\265u\265\323\234u\265u\265u\265u\265u\265u\265u\265\323\234\323\234"
  "u\265u\265u\265u\265u\265u\265u\265u\265u\265u\265u\265J{\351\213W\326<\357"
  "\315\254W\326$R",
};

