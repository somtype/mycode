package Day01

object _03ClassDemo {
  class Person {
    var name:String = ""
    var age:Int = 0;
  }

  def main(args: Array[String]): Unit = {
    var person01 = new Person
    person01.name = "范雨茹"
    person01.age = 20

    println(person01.name)
    println(person01.age)
  }
}
