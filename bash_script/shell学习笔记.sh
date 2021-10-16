:<<多行注释
123
331
231
多行注释
name=fyr
readonly fyr #设置只读
declare -r name #设置只读
unset name #删除变量

love=fyr
echo ${#love} #获取字符串长度
echo ${love:0:2} #fy

array=(1 love fyr forever) #数组
echo ${array[@]} 
echo ${array[*]} #获取整个数组
