#include <cstdio>
int a[10001] = {1,1,1,1,3,2,2,1,3,2,4,7,1,6,1,1,3,4,4,5,8,6,6,3,5,2,6,14,10,2,6,13,4,3,14,7,10,5,10,19,8,21,8,7,13,5,5,6,10,6,9,7,10,23,38,5,7,6,1,5,8,12,31,12,16,6,8,6,13,20,9,25,19,6,25,13,10,35,23,7,5,10,24,18,14,14,20,17,21,44,30,34,29,26,18,12,10,8,14,11,11,10,17,10,9,41,56,55,49,42,11,34,30,35,31,15,35,11,18,31,10,23,16,6,45,3,15,16,31,9,25,45,47,52,36,51,31,18,26,31,72,22,32,36,15,43,29,19,4,22,18,11,32,8,28,20,56,19,9,28,31,53,58,18,17,25,54,5,26,48,24,59,24,30,66,64,33,13,3,66,73,21,4,25,46,36,8,43,31,38,85,25,20,55,72,45,16,20,24,11,66,68,48,55,16,1,21,47,48,20,60,66,14,54,45,29,83,15,79,32,15,19,11,50,15,24,74,7,37,74,58,28,45,32,25,61,49,9,47,3,73,29,19,7,44,45,59,40,24,37,59,112,31,15,61,12,52,4,74,7,18,60,46,130,22,27,85,75,21,40,48,76,33,20,32,38,11,35,17,17,8,28,60,43,87,85,99,61,51,30,15,7,58,58,42,91,58,39,62,17,102,35,40,31,59,10,58,21,70,26,96,85,28,29,64,44,32,20,56,8,7,55,58,38,62,70,75,37,72,37,46,100,65,51,179,97,24,110,76,19,81,30,77,52,87,47,17,20,56,25,67,44,23,31,48,71,19,62,48,30,29,11,41,88,85,52,8,11,21,60,18,66,53,74,82,40,37,124,37,4,39,43,59,53,30,18,35,92,50,51,132,92,35,63,34,45,19,11,48,85,94,9,104,98,77,29,15,146,65,75,101,50,18,35,1,76,45,80,40,32,38,38,63,49,67,117,83,21,51,58,77,87,70,67,58,56,6,60,99,67,41,34,59,74,4,72,53,101,72,13,20,27,10,34,148,104,156,111,26,137,64,104,91,110,68,43,89,63,16,102,30,87,83,86,40,58,77,142,35,105,17,54,22,66,28,50,146,28,48,53,49,48,39,53,54,24,184,9,114,1,20,58,64,47,43,103,40,89,29,62,116,64,45,15,25,11,51,123,73,132,63,145,67,87,129,64,36,85,42,72,40,36,91,108,30,57,18,51,87,26,151,26,154,44,87,104,88,91,41,153,33,29,8,46,26,86,19,89,220,112,66,43,72,43,19,78,63,58,59,87,89,57,46,168,35,120,45,21,29,67,106,30,70,25,126,55,116,38,19,127,100,93,69,88,78,54,26,43,132,58,42,49,25,73,12,23,75,75,98,72,110,62,63,105,45,104,39,100,153,90,29,79,43,45,68,105,50,129,51,120,128,57,31,17,253,44,52,97,48,38,113,11,12,99,80,56,60,102,77,11,40,123,149,21,102,83,38,98,36,58,81,91,63,24,109,39,91,151,217,72,203,55,34,43,28,50,120,22,65,102,57,127,71,59,68,65,36,88,55,49,37,47,24,133,166,38,87,214,3,51,140,62,111,70,40,17,71,175,28,65,37,125,231,118,78,12,95,49,157,5,93,199,53,49,274,98,68,62,12,161,126,23,65,155,195,41,31,51,145,20,74,93,84,32,52,114,227,97,71,27,56,95,98,87,61,86,73,96,46,19,21,67,61,103,107,262,81,121,88,137,23,58,74,117,262,105,131,35,48,38,87,111,73,76,77,154,22,43,77,19,53,58,143,197,102,171,82,40,91,171,85,103,64,32,101,19,161,34,135,143,4,18,89,138,113,66,133,72,11,51,74,61,36,85,61,44,76,76,5,99,184,81,75,46,102,143,80,29,137,119,40,41,23,131,47,195,42,150,170,101,223,205,84,57,51,41,83,54,49,77,76,58,20,28,36,18,20,24,138,103,146,98,163,124,54,120,49,42,173,128,110,81,84,38,139,63,39,51,223,86,49,153,186,114,92,63,140,9,78,13,51,51,12,54,295,62,126,101,88,111,153,21,145,86,60,59,48,43,203,105,151,92,87,40,160,56,40,91,69,280,102,44,73,34,78,227,117,60,107,94,4,58,135,59,42,74,54,30,218,102,252,62,117,102,114,99,96,225,135,58,130,122,143,3,85,274,49,96,104,44,114,69,117,164,43,275,76,41,199,127,200,32,52,149,96,104,98,57,158,6,38,209,98,166,111,148,60,91,176,69,51,7,76,75,128,43,46,17,163,71,160,94,73,52,76,84,145,201,12,112,108,78,191,13,146,57,34,33,265,108,51,117,162,71,60,96,71,173,105,78,106,46,64,133,136,109,49,194,52,92,17,162,53,51,198,76,9,60,148,260,150,67,51,88,199,59,170,70,74,79,181,108,112,188,180,153,63,274,136,246,101,98,27,57,47,189,44,87,48,56,214,367,78,124,167,107,198,59,164,82,70,44,71,78,158,112,216,137,117,237,23,49,126,97,78,79,108,130,175,100,225,58,67,381,154,71,103,97,132,6,81,135,107,43,17,119,198,235,68,83,90,192,104,82,193,82,126,191,64,75,88,182,102,12,158,204,103,180,124,65,63,298,132,218,210,135,144,100,182,138,401,55,79,43,124,60,187,90,90,179,157,62,128,89,89,216,114,86,24,184,276,112,161,75,202,57,118,364,123,163,81,175,70,161,162,234,72,163,126,213,343,109,146,24,26,200,194,94,86,185,162,35,112,127,287,64,120,178,84,44,125,69,49,210,90,135,106,85,139,163,70,179,120,76,339,59,28,104,63,93,51,82,60,140,158,29,135,72,94,37,363,58,113,380,102,142,157,156,203,47,136,120,131,285,39,46,29,88,191,286,62,142,7,109,178,68,238,128,270,181,200,55,366,15,81,270,76,144,203,97,166,91,198,104,352,200,116,141,228,63,86,51,129,74,242,124,154,112,186,87,23,128,142,336,63,324,76,5,288,31,82,97,78,145,102,127,83,97,157,44,292,119,15,173,209,16,127,115,305,147,42,101,133,42,264,61,188,121,28,52,113,135,200,86,87,75,118,85,101,92,90,58,105,111,118,101,74,115,251,186,367,96,30,231,100,109,49,212,50,37,435,109,105,45,97,344,123,152,89,210,98,174,231,206,106,60,14,123,437,40,62,213,114,154,208,204,134,66,77,176,201,133,534,143,60,90,412,341,119,226,37,184,59,91,114,24,88,122,25,394,62,131,73,48,295,289,304,111,150,129,236,148,303,135,19,110,113,63,147,82,160,350,46,257,300,355,242,242,109,92,57,110,109,32,280,83,260,168,52,67,200,96,214,111,107,260,122,193,44,95,219,139,162,223,97,150,95,127,192,32,96,23,99,19,125,66,284,113,118,106,115,74,160,77,159,66,38,257,200,284,102,184,166,137,135,146,52,92,184,92,21,181,212,153,80,189,141,61,61,105,36,35,214,89,189,122,217,108,48,71,40,75,73,124,257,229,164,245,19,147,281,41,33,68,77,221,140,28,45,179,511,416,204,627,112,276,163,116,108,316,112,384,155,109,259,147,249,269,190,56,65,107,294,124,136,174,104,116,147,210,286,75,270,195,366,163,294,95,73,87,28,71,89,108,94,307,75,306,184,227,122,32,42,126,545,281,282,157,286,224,234,190,230,265,197,95,144,77,57,106,103,196,95,422,127,56,59,214,327,224,90,76,124,248,117,133,132,82,267,89,224,411,76,232,149,152,175,132,391,213,43,228,70,399,32,254,128,211,317,396,400,52,111,182,107,62,265,142,100,219,124,132,156,364,482,158,217,80,81,159,251,243,121,53,227,114,133,155,86,71,317,21,314,178,202,324,22,114,192,52,101,232,217,223,206,125,559,147,252,187,116,233,173,173,117,58,138,336,390,371,86,149,70,17,64,105,215,63,143,339,467,272,149,107,142,75,169,112,243,169,73,132,224,200,323,232,282,49,164,213,66,214,152,204,122,79,154,232,309,118,15,124,145,134,155,384,269,131,226,339,149,144,53,80,106,106,72,251,119,91,268,242,140,320,96,11,54,237,118,107,93,1,52,110,192,59,334,149,225,251,260,236,185,66,90,79,385,213,95,74,123,192,86,75,182,256,378,214,163,513,30,72,196,282,174,257,226,45,197,214,164,170,223,148,46,142,180,23,80,177,336,85,197,406,43,89,57,32,76,50,146,96,125,133,35,312,427,186,288,37,15,148,119,89,83,128,331,136,159,330,160,186,293,40,66,96,148,178,150,221,102,240,98,355,151,144,224,136,42,229,306,150,370,453,66,141,67,194,208,49,161,234,173,165,161,523,171,123,288,197,19,146,169,174,102,294,132,13,190,53,33,147,18,32,341,255,117,87,397,397,201,3,66,130,197,84,101,333,119,84,54,207,55,214,283,65,203,274,166,250,447,96,114,264,249,88,104,203,342,130,204,409,162,250,11,129,21,122,122,133,44,71,219,356,114,120,28,191,341,96,257,134,119,241,681,178,78,125,288,311,68,159,375,327,164,353,212,393,346,339,115,148,210,410,81,117,325,61,40,193,217,70,59,113,249,21,46,53,34,67,45,57,115,168,54,324,138,169,396,14,212,216,346,62,185,36,81,74,179,322,70,309,258,48,138,278,107,143,157,342,124,129,59,331,100,169,89,227,217,501,53,411,258,203,84,137,274,219,298,371,44,115,106,225,201,288,108,379,65,140,149,64,214,184,210,251,95,86,43,54,476,408,210,137,84,156,249,145,122,342,179,187,191,83,243,128,98,156,339,246,430,413,323,367,118,105,306,128,269,125,149,315,141,182,135,117,235,4,209,232,173,239,89,154,90,200,423,188,85,252,238,653,463,111,205,161,315,284,65,475,153,155,516,471,108,109,137,91,285,198,136,147,214,19,221,167,431,273,47,161,364,38,162,44,109,477,26,33,100,72,187,125,359,301,140,99,178,125,238,186,175,448,159,811,237,265,478,22,322,150,114,44,44,61,134,241,268,412,298,178,73,93,135,287,326,498,334,151,237,117,132,93,104,856,117,146,87,190,199,173,54,125,200,682,259,102,212,136,268,98,206,143,572,110,193,190,446,116,178,168,142,93,540,106,226,454,48,161,172,291,209,138,108,236,157,120,142,127,247,244,209,157,449,66,282,90,198,231,119,163,150,104,53,213,270,98,486,127,113,201,139,287,315,184,257,94,287,224,143,273,193,576,370,288,231,72,472,293,56,410,124,77,332,89,69,63,143,173,112,140,143,236,42,72,325,376,295,320,31,109,128,530,138,247,90,149,128,71,251,177,145,111,90,393,339,331,308,124,134,240,409,335,599,212,45,280,167,570,363,219,160,21,224,333,191,123,359,162,143,384,166,217,118,383,66,159,77,414,188,313,190,216,82,56,184,108,337,46,164,271,606,82,139,86,118,98,182,223,274,201,286,593,248,164,197,325,401,326,167,339,104,259,412,147,112,22,128,167,160,371,285,262,151,178,228,244,247,293,547,536,320,171,114,57,170,318,182,575,134,324,457,240,203,206,36,180,21,175,218,135,100,145,186,116,39,23,372,261,19,115,55,198,429,231,42,156,426,260,87,49,336,96,322,219,217,245,126,193,32,215,83,197,100,58,200,113,110,886,372,92,119,413,353,133,307,272,246,329,145,267,203,501,157,232,258,56,242,378,233,304,193,127,161,134,153,72,113,332,77,78,203,171,28,164,190,135,306,495,308,335,420,337,240,478,102,164,64,273,339,367,72,189,214,121,209,227,78,224,174,78,256,33,147,333,18,177,294,326,114,212,108,194,252,127,146,185,348,124,128,380,194,528,705,57,529,452,227,36,173,110,145,266,21,27,345,222,210,224,389,501,134,502,522,41,219,253,196,234,250,643,162,193,216,330,212,348,132,245,625,13,30,437,83,35,216,291,314,207,106,252,405,192,221,262,73,156,245,50,300,186,96,253,186,128,157,188,43,123,115,342,203,210,120,225,82,234,258,43,158,367,103,201,375,135,328,291,241,257,194,413,259,27,353,208,308,178,152,109,179,225,291,389,8,180,270,175,27,542,238,283,126,195,485,256,172,522,576,185,305,124,46,71,98,169,192,409,229,311,74,505,147,486,256,698,161,183,399,88,485,215,172,184,205,210,354,150,295,49,228,319,351,302,213,178,435,437,449,171,343,275,43,54,70,197,221,624,159,279,132,511,423,313,263,162,401,316,222,52,247,23,183,299,121,395,139,351,168,244,162,63,230,287,214,199,571,448,261,77,200,138,370,95,256,290,176,536,121,142,69,196,102,160,302,210,17,267,242,65,355,533,326,262,85,73,109,4,33,170,242,594,216,125,322,114,96,138,24,83,32,299,582,240,233,158,294,76,103,30,158,549,556,291,161,61,162,184,252,304,479,164,562,102,123,520,305,200,36,314,201,147,161,36,359,435,606,362,281,178,284,269,45,229,170,299,213,206,213,101,195,135,144,172,188,129,157,165,254,68,266,265,411,342,188,158,122,324,498,108,149,64,95,44,830,163,229,228,118,317,110,468,74,155,407,103,266,70,212,216,380,324,541,7,161,601,275,181,309,55,134,296,124,530,172,441,64,113,178,128,871,481,798,173,221,764,629,189,236,246,192,162,213,253,86,224,197,155,332,337,571,259,386,88,195,190,346,221,224,168,358,405,142,23,117,194,147,306,172,155,260,155,379,593,653,472,209,155,215,198,456,870,209,128,159,194,457,74,144,392,208,177,71,125,5,58,162,189,254,148,278,189,816,244,107,183,119,163,125,44,90,291,41,228,541,193,253,714,137,600,332,101,117,284,149,410,259,315,181,282,97,133,158,136,329,266,246,61,46,87,293,264,499,239,142,316,120,104,91,340,388,168,185,242,487,71,327,171,93,423,318,179,332,50,138,447,558,149,109,396,85,86,105,637,34,174,138,33,195,411,140,469,242,318,108,126,45,619,166,137,69,188,171,283,285,81,111,20,260,83,327,86,333,775,432,236,156,518,170,143,410,286,455,103,267,86,193,346,324,264,271,250,473,627,269,338,271,419,120,389,198,264,129,251,356,223,379,210,277,219,234,367,226,512,139,128,167,930,92,322,421,278,55,274,555,211,190,224,447,345,111,754,67,348,739,798,263,85,845,291,471,471,191,158,51,172,407,619,77,114,531,118,128,476,277,309,245,204,296,355,282,499,390,121,577,292,296,235,399,144,83,53,36,321,117,94,206,37,162,506,370,216,272,435,702,57,543,663,46,191,218,702,400,147,363,235,441,271,376,256,75,370,308,728,72,492,325,206,335,292,278,512,150,235,93,434,236,118,465,153,403,470,301,69,175,18,175,521,637,447,312,135,158,484,57,367,274,85,108,141,202,200,157,98,516,623,676,401,294,399,140,569,530,228,201,600,281,70,458,521,262,332,328,108,165,104,735,336,166,883,49,141,645,64,480,201,306,241,102,171,516,110,150,233,405,164,255,342,478,302,165,120,140,56,232,96,288,238,65,257,528,360,290,185,347,772,231,74,106,860,666,247,124,215,176,57,463,531,451,213,156,212,49,704,113,289,53,566,207,603,224,807,115,266,150,278,384,302,436,378,161,202,25,331,449,174,230,371,619,312,534,269,424,132,280,123,194,429,21,151,441,409,198,180,129,367,557,423,135,284,331,73,73,362,575,529,88,618,494,140,174,179,211,207,255,143,198,223,193,439,314,240,221,420,34,273,129,212,60,234,440,254,252,171,433,207,28,349,405,186,84,439,329,107,227,384,516,201,324,245,313,91,102,94,321,201,79,97,192,263,6,477,118,653,72,326,569,517,166,288,386,153,170,63,442,71,169,171,10,270,399,261,110,849,346,268,534,260,170,34,499,164,140,344,313,283,511,853,135,634,181,263,1004,228,170,277,741,1018,189,113,230,98,414,312,314,43,588,147,227,277,281,186,194,190,239,199,84,284,533,372,426,79,369,381,413,58,51,129,210,43,139,521,456,170,725,336,195,65,234,255,520,480,455,603,205,203,380,68,104,285,185,255,8,288,689,33,402,542,354,588,624,421,103,197,152,338,557,192,133,186,236,632,496,201,355,374,298,495,74,277,606,147,186,104,236,623,478,200,358,40,262,61,216,597,225,195,416,122,212,433,667,508,144,73,361,230,528,333,138,129,453,149,497,279,318,132,46,221,452,467,289,191,156,224,280,366,338,926,286,18,48,44,339,212,231,475,518,524,265,57,347,648,399,268,47,327,281,182,84,47,708,333,213,5,227,327,178,266,362,700,259,401,406,283,619,541,197,440,93,164,420,136,44,181,286,17,350,143,389,451,28,54,751,87,241,523,67,471,399,111,356,351,136,125,170,378,343,186,293,269,57,133,321,119,249,319,41,519,203,338,134,569,249,189,235,81,140,370,224,299,260,278,313,474,210,34,172,215,124,389,432,771,173,244,179,191,236,427,439,436,125,95,166,130,217,93,200,596,229,125,638,423,264,129,1124,347,157,80,444,89,632,99,72,89,143,140,175,242,585,182,179,222,386,148,243,181,104,148,406,75,56,373,40,67,410,190,227,98,143,232,306,339,171,373,198,237,129,444,357,678,474,205,417,477,640,215,93,232,489,226,599,466,356,254,241,511,378,270,538,380,239,222,57,560,298,591,218,194,116,469,143,127,254,321,12,20,135,787,270,260,400,406,275,197,205,333,405,415,148,10,179,205,467,741,212,254,303,149,250,173,122,89,107,160,294,603,527,132,381,213,132,239,35,265,315,236,357,492,423,200,512,257,227,702,381,451,281,243,84,363,441,613,613,244,637,298,676,229,356,336,74,734,229,198,376,122,265,167,366,141,181,159,233,318,118,360,290,157,414,309,350,521,511,608,133,674,429,118,539,136,395,559,442,163,193,448,287,679,247,316,176,431,115,229,209,127,255,82,269,132,157,811,641,375,164,261,249,202,739,280,301,556,504,470,96,256,167,595,126,238,373,419,175,176,430,120,411,122,375,386,85,361,660,151,65,177,453,387,258,217,432,613,465,325,272,139,172,317,202,280,408,599,450,106,567,281,225,496,257,407,161,860,423,285,119,201,658,346,253,635,209,263,468,257,407,327,373,153,339,181,360,126,267,585,178,99,184,294,166,419,163,115,207,203,157,560,216,34,157,61,382,570,200,451,105,212,701,308,119,201,260,331,336,317,308,36,191,308,370,592,516,132,374,16,583,136,185,304,184,275,331,204,281,365,177,185,173,351,201,92,179,287,220,211,452,49,384,50,62,59,41,1042,140,370,413,255,419,198,406,613,351,336,216,709,570,376,99,304,443,379,359,517,280,106,486,285,398,431,421,145,183,178,222,222,232,219,253,288,453,50,118,485,616,285,341,230,207,197,77,746,210,890,185,73,400,171,389,77,227,415,72,156,290,373,169,257,164,153,276,260,307,473,361,162,592,413,43,149,119,481,413,408,109,250,559,186,358,48,1290,614,259,653,447,809,297,249,159,111,182,93,259,295,252,574,346,532,631,434,528,115,188,386,179,220,75,349,69,517,262,114,579,478,17,451,150,1202,350,547,580,367,407,842,467,187,105,453,574,432,26,560,315,310,134,668,544,461,119,209,30,34,282,158,341,225,63,34,204,137,75,170,254,223,630,60,319,502,682,159,110,447,503,194,122,453,205,372,515,32,285,274,401,620,62,203,546,347,242,233,232,936,502,520,130,139,28,390,717,138,490,320,457,419,837,904,130,479,107,312,253,22,471,216,456,186,391,241,438,371,132,242,472,309,188,250,371,402,649,149,297,61,996,128,471,194,203,234,263,173,133,317,250,63,108,136,672,667,419,212,269,286,378,248,271,317,42,157,496,264,405,415,128,124,388,339,177,233,228,283,308,276,384,333,148,227,201,404,80,32,456,512,318,933,62,208,213,590,275,625,652,376,60,145,551,295,227,322,89,364,182,208,309,292,325,137,631,297,210,804,171,417,218,234,211,336,613,245,259,135,280,159,330,794,14,382,110,533,549,288,227,569,276,208,238,187,518,554,330,709,932,1059,346,264,381,912,15,533,273,305,393,156,189,208,362,315,389,241,87,265,36,447,408,294,275,674,558,424,386,516,156,328,450,562,256,196,397,552,243,632,95,180,221,204,321,142,326,106,617,497,360,339,257,37,1042,72,115,940,307,148,495,466,767,575,123,283,601,506,406,695,401,396,130,422,319,80,557,441,218,935,384,266,434,44,436,95,331,510,321,463,299,156,159,198,332,146,355,57,230,207,537,170,469,356,402,742,297,949,319,437,61,487,284,264,723,484,352,186,203,144,603,390,368,147,258,241,554,288,435,408,749,338,47,53,315,472,299,182,133,272,365,321,432,429,226,184,642,645,172,447,377,315,343,210,334,285,267,397,440,235,127,280,312,83,221,439,216,294,152,163,424,535,211,251,544,385,98,55,351,245,447,272,314,113,181,223,400,345,198,104,207,286,392,159,128,552,65,149,262,415,46,362,344,173,342,105,426,377,293,223,480,348,354,229,384,746,194,50,197,250,155,264,311,296,346,95,112,335,325,199,12,771,415,329,180,77,429,339,37,949,206,628,118,186,207,229,536,389,68,480,253,342,172,40,381,400,187,152,476,476,441,465,484,156,743,273,245,335,340,618,75,388,465,765,45,544,391,55,385,437,82,410,194,698,549,160,283,545,170,591,139,385,176,549,615,455,304,445,720,455,149,642,283,324,678,303,636,149,365,108,188,372,358,475,122,358,552,103,548,421,221,171,354,192,363,1243,350,231,513,451,74,690,619,335,86,805,114,138,114,100,520,519,531,307,582,226,250,171,246,363,580,470,250,706,582,256,318,268,248,40,214,191,618,308,209,346,354,181,232,472,164,102,305,398,354,19,845,387,533,255,914,192,183,233,158,332,324,414,108,142,710,847,328,110,348,357,313,201,197,301,290,261,394,452,26,279,249,218,33,40,411,550,1168,653,1270,394,477,765,254,176,591,290,434,438,145,328,304,187,216,418,8,196,618,101,570,469,180,563,83,403,1164,566,314,275,384,116,685,458,377,318,22,168,220,394,352,924,60,498,965,286,530,481,209,125,240,229,432,409,298,582,658,700,289,499,400,60,209,41,469,754,533,249,571,218,399,72,374,322,186,604,287,304,535,250,112,152,220,222,160,483,180,174,301,58,71,401,292,80,949,513,486,566,1002,288,423,710,140,99,613,334,1333,299,362,177,170,804,12,362,221,391,489,443,478,386,332,296,508,339,526,215,1030,573,291,362,932,353,291,896,767,609,582,542,61,125,193,223,39,1113,231,399,552,455,250,250,801,97,754,450,532,493,334,320,235,330,569,231,411,420,653,80,377,581,637,256,473,523,463,174,279,814,69,466,45,1000,727,400,447,52,792,688,122,63,480,297,79,395,124,33,283,332,680,356,1355,209,176,577,336,183,221,77,137,167,216,468,394,89,750,252,156,643,55,185,193,65,377,622,590,112,560,55,440,601,72,279,184,212,558,427,572,160,278,22,469,228,235,112,344,332,605,622,482,333,259,210,73,319,378,325,264,510,374,436,158,356,88,226,400,262,106,311,140,226,364,277,291,612,480,310,387,289,610,288,329,47,103,1166,268,361,190,137,319,350,247,223,225,604,475,751,361,485,100,146,22,219,410,916,394,123,263,246,182,660,398,1131,355,175,382,231,225,385,516,163,470,207,22,79,476,256,614,631,145,44,137,681,849,492,368,209,407,244,286,359,658,286,289,380,330,294,531,468,1268,410,162,425,479,831,262,354,202,424,1267,230,567,506,277,589,777,13,594,175,99,911,372,274,580,654,121,296,150,9,186,431,426,505,145,501,125,188,285,315,366,277,292,211,821,275,921,1006,155,297,205,565,241,252,438,367,103,150,724,435,331,118,439,249,217,475,85,582,329,425,570,11,613,363,338,699,90,1083,349,273,486,1060,182,636,640,384,666,549,314,342,551,683,316,321,475,537,475,133,345,588,28,172,271,180,214,138,330,221,638,229,175,335,548,11,277,467,265,324,493,434,108,620,1054,206,162,197,593,372,323,335,401,536,884,91,519,293,545,317,513,332,282,244,293,328,266,526,236,997,176,517,535,420,882,175,584,400,360,74,275,579,212,382,156,88,161,58,30,1211,296,346,133,337,568,207,425,531,939,247,13,431,34,284,306,580,80,241,122,440,649,159,690,478,111,989,244,254,908,656,398,243,406,116,114,341,246,584,315,615,600,576,410,252,98,600,214,469,367,198,119,807,524,733,153,167,191,417,426,539,476,256,105,208,52,404,191,237,999,487,265,853,188,109,558,666,350,202,383,217,445,140,1035,110,467,127,231,351,279,239,280,605,357,184,331,427,569,429,929,865,433,316,248,381,775,201,507,267,465,668,84,1010,494,439,360,212,560,534,852,230,206,930,377,797,94,264,894,342,168,361,260,133,190,139,102,270,38,272,546,160,1094,511,234,437,822,702,1489,319,252,492,267,737,233,273,177,145,238,249,485,452,99,265,482,234,419,444,412,212,192,195,706,206,433,129,710,319,542,177,412,220,833,269,77,298,131,789,120,409,619,373,358,187,435,572,604,233,343,257,523,299,406,256,243,395,413,511,1100,654,531,276,562,25,756,191,9,268,339,414,869,459,301,155,53,503,419,272,228,332,139,64,183,195,196,494,488,258,55,216,148,346,179,761,308,637,85,371,91,575,377,152,495,389,321,198,447,126,317,336,443,614,514,338,380,862,157,196,160,412,662,351,608,89,444,312,262,1170,293,208,81,570,437,125,165,480,615,704,625,261,869,741,684,283,380,693,133,1057,590,61,184,728,262,116,392,384,455,448,606,605,401,222,653,31,124,532,384,939,81,606,332,602,535,752,192,296,307,440,620,443,242,265,378,117,204,756,390,237,383,352,99,478,318,605,401,44,459,465,438,941,427,706,325,1076,982,50,406,416,290,496,197,268,129,166,324,312,707,508,321,28,463,186,552,503,618,360,187,478,603,94,769,400,294,363,67,921,284,211,696,108,287,337,246,79,292,523,469,306,322,304,70,270,346,285,462,484,346,303,956,636,508,142,257,226,442,293,226,346,595,527,189,151,272,690,352,446,291,331,365,170,142,668,257,925,121,329,229,680,249,853,601,714,482,306,218,250,312,89,305,367,527,414,630,269,628,108,388,68,514,163,213,313,84,306,438,228,239,327,293,866,250,466,382,553,220,852,471,371,25,397,262,407,136,237,242,992,783,380,274,456,238,158,529,533,493,671,71,285,138,228,38,201,420,59,191,372,164,471,15,244,384,278,410,620,385,358,260,435,235,592,394,322,1312,770,431,470,598,364,915,716,276,715,257,368,180,712,262,312,433,327,579,1737,189,383,793,585,392,486,248,586,252,287,719,565,398,823,252,194,344,282,197,410,493,543,237,33,390,109,982,71,99,763,233,1241,247,784,674,187,40,505,269,1001,231,273,238,370,287,306,696,262,92,1776,49,965,155,420,242,294,523,330,201,521,290,266,285,256,131,8,73,210,359,218,165,1139,364,984,190,75,304,419,616,604,433,148,994,656,137,555,327,552,567,25,1883,525,251,274,522,812,895,156,351,1036,865,288,1002,390,463,244,408,211,371,845,589,423,72,569,300,708,103,416,315,340,714,311,831,162,261,481,683,239,328,572,193,128,475,769,1002,157,145,169,117,368,96,574,298,55,623,976,183,302,485,330,561,125,865,169,959,420,617,178,324,1238,1047,924,306,123,593,210,593,532,308,97,305,411,260,718,730,168,174,345,644,101,972,230,544,899,971,91,327,105,172,45,909,200,177,164,212,313,421,829,613,472,275,256,219,415,219,267,804,409,385,268,383,75,336,282,946,589,282,195,685,672,155,510,459,529,595,443,245,221,282,174,326,518,481,746,575,145,605,441,988,206,454,178,194,400,70,172,248,398,408,851,857,101,213,390,375,85,396,641,497,1013,277,484,382,640,211,171,517,179,535,180,248,155,123,594,161,146,372,1071,396,675,782,166,982,538,52,25,107,347,258,206,13,299,310,338,633,621,249,698,462,396,65,732,961,340,331,825,312,271,916,614,64,440,239,322,323,434,432,918,455,213,393,176,384,713,502,364,602,363,187,573,130,471,101,225,121,244,426,471,132,525,280,996,185,513,266,718,202,606,236,447,265,182,436,1064,509,985,602,213,459,232,582,359,554,56,440,275,965,662,321,443,952,689,205,317,39,345,556,639,210,284,477,308,540,339,295,578,193,300,215,776,187,142,792,570,199,562,511,400,552,563,180,520,498,439,46,616,260,691,936,365,341,438,972,267,139,336,158,296,672,443,421,365,842,482,211,270,295,14,214,746,323,457,228,1210,398,330,438,218,349,395,1055,160,765,1255,538,459,508,247,232,286,1125,533,342,382,328,1008,759,674,542,377,352,119,573,114,363,525,251,313,788,149,345,120,143,350,60,486,380,426,851,268,270,532,451,430,25,343,454,575,102,406,258,226,320,81,194,209,260,186,346,315,300,625,294,632,626,315,279,172,312,1172,470,411,274,342,457,610,177,255,414,764,751,407,412,403,746,283,166,482,324,373,475,438,913,269,156,217,621,602,229,251,282,238,189,105,224,455,327,1058,568,352,693,404,205,826,425,83,463,943,215,648,211,190,482,827,565,491,1151,471,433,563,580,725,866,330,809,541,304,504,285,610,858,390,97,258,216,678,380,492,1028,806,261,964,797,263,656,739,268,699,380,433,70,1093,157,255,766,373,392,169,379,1044,285,442,279,387,641,53,390,467,345,292,412,327,442,716,80,554,802,453,318,672,336,259,1122,702,242,249,376,724,268,550,525,504,793,760,285,296,487,412,390,489,331,418,190,338,182,294,563,389,324,290,1102,1050,147,473,731,267,487,759,72,316,498,292,315,822,519,170,1377,108,137,471,268,510,807,242,547,361,211,854,874,352,411,74,245,483,1338,338,1297,908,2207,191,335,1167,528,999,217,341,205,296,1054,227,211,154,1310,626,377,346,509,197,163,212,779,244,95,328,159,339,245,632,462,287,576,516,322,401,353,561,166,173,142,273,197,955,728,363,286,93,110,298,411,192,231,433,174,976,505,324,385,807,602,567,819,673,155,1034,275,400,374,168,537,338,686,322,553,480,683,557,419,512,174,1186,599,656,995,2,61,283,394,76,443,517,591,825,293,157,653,1059,248,427,1021,55,1232,553,264,263,134,367,533,663,99,159,135,357,108,318,432,144,122,225,551,1141,575,190,161,77,766,414,485,1111,69,206,680,94,383,135,560,1066,353,320,374,526,251,187,549,324,387,415,258,357,426,797,551,464,276,700,176,679,208,766,974,861,594,613,364,259,331,301,831,322,152,283,818,592,494,655,52,658,428,119,521,220,293,848,122,364,848,386,581,337,238,657,293,501,645,335,433,993,161,210,1237,140,460,709,814,319,296,179,103,91,922,533,590,1023,529,659,518,435,329,179,495,99,166,326,111,115,554,331,613,256,298,479,435,459,449,656,917,568,1082,268,1089,97,37,401,535,378,380,316,217,479,526,667,288,369,477,452,101,124,370,652,428,175,135,234,845,850,513,152,606,141,222,396,152,298,569,33,390,314,185,307,168,622,210,545,164,306,325,273,309,129,356,378,794,367,492,1813,321,384,5,440,461,285,549,165,61,951,510,333,781,594,73,233,306,198,419,635,867,334,674,166,229,273,491,315,966,174,773,619,191,357,286,779,792,737,578,283,147,267,882,693,183,24,164,1026,157,165,496,317,193,76,314,478,920,424,173,555,780,217,212,558,439,403,581,440,572,368,822,1289,774,330,510,711,280,276,334,508,1039,184,389,247,589,462,358,386,673,599,771,210,505,427,135,1477,245,335,1014,417,319,591,164,639,397,157,278,402,1050,155,111,113,286,264,184,171,397,687,427,587,6,327,377,596,383,436,469,362,847,773,6,409,243,327,360,464,773,229,252,419,438,223,386,514,1158,1511,814,264,516,367,469,273,227,847,974,168,702,428,220,1169,783,253,196,153,230,211,596,429,1286,215,319,316,304,582,896,1200,164,273,856,368,665,586,182,106,378,570,101,122,35,40,665,55,788,236,217,322,998,73,462,628,345,675,135,361,127,37,45,429,169,435,266,405,57,470,303,657,63,684,374,364,512,5,64,465,278,736,509,455,837,303,296,1686,558,187,288,559,84,94,142,236,1064,815,278,371,381,241,402,685,327,159,381,567,1558,190,515,64,698,295,432,677,410,359,205,1038,354,213,411,211,582,630,263,346,594,299,608,444,270,301,144,1024,1226,136,188,418,126,912,120,79,1199,455,371,451,377,519,642,615,100,386,567,287,72,691,1653,256,320,716,147,761,156,505,243,327,215,497,377,164,371,355,616,710,376,100,33,1130,349,459,625,444,407,383,600,801,1036,676,689,542,171,171,908,287,344,349,823,440,583,666,110,404,322,916,658,1092,959,882,164,219,21,512,605,422,511,722,928,614,316,535,350,249,143,400,1068,363,972,227,1618,511,906,1080,762,591,920,885,590,700,363,618,472,192,279,842,630,1152,950,651,123,581,753,343,396,278,395,378,779,560,228,942,449,385,195,263,57,528,215,314,151,438,996,56,905,175,429,224,1143,727,361,264,2,249,174,121,60,868,633,345,399,596,298,389,555,259,326,480,935,524,605,143,1534,348,582,178,311,92,620,171,776,277,263,512,297,219,251,975,1062,199,301,67,276,466,869,430,415,53,637,477,351,252,163,573,131,1033,174,200,254,350,626,585,817,491,768,314,218,515,685,177,546,284,46,460,720,457,657,727,158,813,226,705,1292,496,214,558,301,479,618,436,1006,444,453,1096,216,817,541,199,433,775,1009,739,298,419,358,776,126,820,982,525,439,1033,189,276,322,163,651,183,639,404,489,933,239,884,208,972,465,1119,1416,374,461,339,65,362,1437,240,306,706,447,484,175,158,512,576,232,690,391,414,282,430,660,333,317,537,10,116,499,110,873,176,489,224,493,1075,746,147,676,1241,229,316,965,349,452,704,588,830,873,491,756,183,813,423,791,624,217,259,642,482,591,453,452,406,369,426,525,410,605,268,192,457,254,589,754,788,286,1551,645,644,856,333,457,194,568,585,274,661,818,1100,458,159,155,186,386,438,309,714,1015,531,1473,99,101,628,318,192,112,1326,517,609,147,189,558,185,572,970,412,84,183,498,122,394,444,843,1009,388,109,399,506,433,505,317,301,504,445,307,93,622,1105,400,617,378,1178,232,449,1211,10,546,731,552,198,939,114,92,543,289,177,569,416,126,1205,498,47,591,587,573,354,445,235,551,144,714,99,109,21,83,395,1527,187,173,294,255,793,657,1228,658,1118,514,482,327,739,208,430,614,253,391,335,304,905,272,104,1000,1203,632,415,404,34,788,635,520,457,276,151,413,474,327,851,184,695,327,750,149,624,382,230,422,182,404,459,469,580,611,229,594,177,1250,341,409,287,249,577,537,933,556,1017,506,338,690,831,487,252,608,913,1021,580,553,274,73,1030,342,309,648,1007,622,564,860,247,186,593,308,223,1536,419,416,581,273,338,201,429,647,306,356,371,19,256,621,869,712,94,666,472,163,890,187,291,286,753,602,66,264,359,453,567,626,221,1111,249,1040,558,395,291,812,168,466,389,124,468,337,950,68,487,302,843,540,462,583,1024,1011,277,1175,392,310,455,128,725,297,797,502,442,805,982,284,407,48,479,403,112,468,496,75,403,503,312,428,411,1176,443,1007,509,121,550,714,654,1727,672,1490,623,396,313,395,709,786,656,614,417,551,376,781,729,388,272,705,979,111,745,781,617,448,1265,1430,1266,789,412,435,309,559,565,503,440,456,315,369,495,1217,500,525,453,153,1243,1048,754,53,209,270,734,348,327,644,672,1110,829,486,483,132,722,295,478,265,483,473,293,62,479,679,193,723,953,86,375,609,593,403,466,370,319,986,1514,620,271,42,709,1260,235,358,535,483,387,357,1117,539,479,237,217,716,400,749,335,568,420,739,1355,735,479,496,283,614,741,473,650,686,452,560,145,354,322,263,356,1048,655,258,535,577,481,591,76,237,252,511,421,1682,635,283,372,798,335,809,346,331,177,588,167,537,984,1048,1152,247,125,630,1482,295,401,357,823,1012,63,360,465,622,573,393,458,832,172,382,18,553,291,963,412,180,1307,88,792,272,275,318,143,183,593,558,541,634,705,693,607,459,156,618,1631,619,806,531,420,392,230,386,442,964,705,667,463,1033,922,186,518,524,558,389,578,769,1159,665,67,61,176,512,1314,1345,282,585,449,556,339,1304,262,972,205,152,966,261,378,324,662,622,119,558,278,419,572,900,781,711,329,538,389,414,803,329,791,217,203,292,847,806,433,111,180,59,244,518,434,572,16,267,458,1703,479,348,1378,526,413,571,1098,108,337,498,502,142,346,468,235,740,285,1517,407,455,329,346,485,595,845,412,403,370,785,894,420,696,644,213,413,493,418,590,1217,304,814,439,152,795,982,64,465,300,441,353,337,680,197,719,753,267,132,977,398,471,833,390,326,239,1135,346,134,601,804,127,569,398,818,426,610,203,517,785,540,868,543,251,385,1518,282,1092,521,943,616,1140,1609,892,144,464,818,396,283,215,98,635,221,766,470,388,477,485,316,231,754,1043,486,835,333,865,665,612,283,1303,1002,296,173,259,873,384,156,79,244,207,274,279,1470,387,1043,125,872,938,804,423,772,70,221,615,262,201,638,558,471,118,908,556,1118,665,364,1031,312,840,336,106,1664,473,714,579,1371,356,471,95,515,660,313,676,1363,690,404,402,475,208,114,172,149,812,602,466,362,486,782,310,97,401,311,1148,273,475,262,853,378,943,947,974,423,306,212,252,344,173,415,717,675,792,971,849,309,501,836,840,55,85,575,607,567,585,95,17,318,733,221,689,659,434,1422,824,691,482,237,294,515,467,1449,810,695,672,419,41,356,915,494,457,311,321,249,374,371,686,620,212,383,367,419,248,576,684,578,66,184,541,717,252,705,521,375,991,375,288,820,177,219,441,308,201,1489,320,313,144,366,336,1067,376,144,647,913,820,22,416,262,1154,971,858,115,116,561,781,362,323,1228,84,506,210,1556,230,332,692,502,425,1314,1831,687,469,171,990,443,1379,500,410,1152,391,46,312,520,216,504,300,398,139,572,1308,642,308,750,1389,81,1022,566,1088,506,744,826,421,424,450,525,676,97,472,816,848,301,1017,218,432,48,653,328,348,810,475,292,185,544,676,458,429,675,84,429,428,889,528,266,96,727,866,393,534,231,423,369,540,1323,833,686,623,199,640,679,742,513,396,281,1036,283,563,606,845,557,505,300,24,619,515,1437,1015,440,939,639,272,954,685,1769,718,359,138,1799,279,725,202,242,681,582,791,904,1297,690,180,704,644,252,836,277,604,74,173,205,135,284,696,194,115,470,261,249,345,1080,215,885,634,77,699,168,268,278,627,445,586,1230,154,224,701,176,266,1229,372,367,999,534,1129,338,179,1085,1134,821,91,801,1176,520,339,409,214,675,930,490,181,296,413,356,213,575,117,64,750,630,1751,126,364,208,562,746,1406,262,258,59,268,922,175,414,1337,1239,427,1312,491,321,142,298,714,664,627,1208,420,812,872,189,120,389,657,729,673,899,1637,360,1502,957,102,661,611,326,998,1192,1214,188,419,933,123,126,1038,1064,138,452,890,789,43,789,227,1110,870,294,305,869,537,642,233,491,89,418,1012,9,146,948,104,718,546,822,308,722,7,1317,223,239,152,561,554,134,776,311,572,214,1292,23,712,402,935,445,411,186,1064,256,1287,756,159,898,670,2277,534,718,356,463,324,172,253,506,758,526,788,732,82,340,230,593,158,470,399,317,237,965,887,1020,311,337,497,332,732,214,327,224,571,242,590,490,520,605,121,1803,1398,726,458,960,732,245,173,693,805,341,429,299,359,484,441,399,571,896,55,295,1539,423,871,240,596,117,755,719,500,700,42,611,281,908,184,162,1102,24,987,372,159,349,43,942,439,242,838,692,400,416,883,484,514,693,528,835,733,608,471,348,624,392,503,141,578,547,177,281,1914,965,1386,601,543,266,767,45,782,242,1035,682,410,520,1019,286,298,404,315,1053,468,506,525,1630,442,82,219,683,1269,966,552,414,194,810,320,415,1169,753,188,141,195,390,187,424,1011,301,846,186,358,127,718,355,400,393,748,588,315,529,571,1182,953,1216,665,542,691,365,783,234,542,1117,462,743,531,502,930,996,391,465,304,376,228,186,380,371,785,851,1211,585,58,742,740,416,1688,586,1157,799,392,1221,129,624,479,925,351,344,568,418,363,1167,322,451,929,1702,881,797,546,301,262,245,1514,1361,819,419,706,207,636,593,617,345,64,248,365,1189,317,981,155,785,977,203,443,1311,305,588,447,780,627,516,833,526,755,238,279,525,543,570,235,1502,1081,729,401,73,1032,550,1198,160,203,626,1010,71,481,1664,327,463,184,1109,239,863,494,550,1541,455,821,658,689,1075,500,271,271,891,1038,229,249,99,247,443,732,760,375,464,1496,495,383,839,443,424,235,848,448,747,800,98,1097,427,73,546,1249,526,371,341,907,234,398,1355,731,205,497,218,402,623,88,846,295,602,1111,572,287,772,1675,26,705,369,246,332,300,593,295,335,449,527,1182,764,861,354,568,1424,383,276,468,455,480,1317,711,294,420,840,1478,550,481,499,570,378,321,512,566,1130,474,1083,1107,714,120,637,233,875,543,433,275,394,386,39,285,93,1241,483,335,898,289,536,245,153,110,822,356,617,721,446,937,698,202,989,731,879,318,437,398,757,16,466,813,273,2054,413,549,452,464,438,868,874,766,279,1458,352,323,747,972,245,104,420,220,957,321,654,269,446,749,347,800,554,1461,819,314,855,957,644,422,347,256,593,955,581,613,321,388,1448,489,877,507,272,192,560,771,319,370,273,423,451,1643,308,194,187,1190,259,1071,1046,1005,291,45,722,473,660,514,1043,861,1332,463,515,190,932,401,697,546,830,978,222,688,483,272,408,456,458,427,699,306,445,733,545,236,229,360,768,603,169,612,479,165,983,705,259,661,885,929,162,610,1427,544,664,451,355,1664,677,408,376,1940,532,416,514,356,120,1056,1180,550,629,579,588,354,617,548,650,373,454,199,493,462,496,638,347,386,376,84,758,810,693,1023,762,522,327,442,957,188,1230,448,923,255,499,454,435,161,1,320,694,178,1026,539,152,528,959,946,160,643,787,192,927,180,1598,90,1164,737,373,290,421,652,148,122,752,519,680,1875,370,1022,538,222,3,86,614,649,335,289,518,762,263,446,396,594,290,581,901,662,980,451,1177,487,1118,781,1486,366,126,436,492,710,159,1172,333,513,742,285,583,405,142,685,978,812,719,259,1371,739,428,251,867,484,599,127,946,372,1078,1065,504,1053,362,760,124,415,443,785,932,352,792,713,733,422,993,166,187,278,1023,228,729,457,451,121,409,898,511,408,1024,832,380,326,300,552,499,409,240,514,584,227,358,234,503,648,982,270,486,263,563,678,229,792,82,868,226,149,565,577,852,1874,633,571,1448,134,216,908,294,751,746,408,628,746,906,477,293,1290,670,125,601,1341,718,1138,277,1524,906,671,830,560,510,1959,370,132,512,742,528,768,854,546,419,1332,189,762,512,911,295,454,828,1263,616,933,434,985,348,269,679,486,24,514,490,711,5,867,397,1628,460,404,669,474,235,671,745,837,122,196,255,565,424,321,248,230,1854,375,1079,740,1295,335,870,57,657,972,632,497,157,404,972,461,215,1540,973,120,1256,308,299,363,1649,185,341,372,949,35,1161,877,753,711,751,918,891,1017,712,973,1318,783,339,1578,437,537,552,340,1524,153,257,122,1067,625,735,406,670,123,1025,737,1306,410,487,402,574,538,411,169,983,469,429,286,2241,847,549,1171,439,396,1319,374,276,638,573,1206,364,326,372,1004,543,856,1362,339,534,548,369,993,696,472,853,257,491,128,807,650,978,465,383,582,336,476,566,695,206,638,493,968,571,699,1158,181,426,1028,1276,708,726,98,993,335,572,1210,500,391,253,611,552,896,521,944,1380,399,677,63,702,939,504,830,349,94,285,812,512,796,237,888,1165,548,100,914,523,499,134,1397,438,1273,307,637,613,337,320,533,251,391,441,802,1358,629,447,575,964,918,1125,201,837,518,306,923,659,489,780,554,603,560,623,39,1738,1680,1232,523,432,500,300,1143,1298,787,636,426,358,613,990,851,270,1056,407,643,276,1019,702,598,489,1016,936,709,527,186,387,637,1140,1029,354,445,297,331,1286,219,372,573,647,681,765,757,342,183,768,980,326,855,606,358,774,489,232,286,218,704,449,2122,859,305,255,741,737,1090,580,642,395,751,599,788,1400,1855,1075,965,686,718,827,40,542,419,530,84,240,1759,250,686,835,347,133,1513,323,922,206,915,93,582,1290,917,932,379,1446,494,741,109,213,1180,1453,334,582,345,770,899,852,766,256,800,983,648,1102,688,925,1042,263,397,786,780,413,815,938,659,691,38,905,897,856,421,499,214,663,522,859,41,1760,510,626,281,1083,539,537,804,615,362,262,347,950,398,167,1229,900,326,926,577,438,454,666,420,313,853,285,249,1462,302,505,53,1251,314,907,338,1191,908,92,351,756,942,1432,191,645,714,1944,408,799,618,907,665,520,547,325,918,669,1999,448,28,376,318,277,655,1295,327,619,676,1127,60,704,744,931,264,290,456,1002,395,1029,293,302,466,211,272,672,872,853,209,539,286,363,650,654,128,106,401,1477,509,445,376,307,1214,781,539,228,261,1121,363,472,378,1252,922,734,808,509,425,433,617,481,624,193,538,1552,470,917};

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n]);
    return 0;
}