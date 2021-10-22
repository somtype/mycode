package Day01

//有关修饰符，没有public，没加private/protected默认就是public
object _06ClassDemo {
  class Person{
    private var name:String = ""
    private var age:Int = 0

    def getName() = this.name
    def setName(msg:String) = this.name = msg
    def getAge() = this.age
    def setAge(age:Int) = this.age = age

    private def getNameAndAge() = (this.name -> this.age)
  }

  def main(args: Array[String]): Unit = {
    val person = new Person
    person.setName("范雨茹")
    person.setAge(20)

    println(person.getName())
    println(person .getAge())

  }
}
