package Day01

//主构造器
object _07ClassDemo {
  class Person(var name:String = "", var age:Int = 0,
               var birthday:String = "", var lover:String = ""){
    def printInfo() = {
      println("name: " + this.name)
      println("age: " + this.age)
    }
  }

  def main(args: Array[String]): Unit = {
    val person01 = new Person("范雨茹", 20, "20011229")
    val person02 = new Person("邹鹏飞", 21, "20001123", "want 范雨茹")
    val person03 = new Person()

    person01.printInfo()
    person02.printInfo()
    person03.printInfo()
  }

}
