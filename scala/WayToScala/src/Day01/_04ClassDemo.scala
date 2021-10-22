package Day01

object _04ClassDemo {
  class Person{
    var name:String = _
    var age:Int = _
  }

  def main(args: Array[String]): Unit = {
    val person01 = new Person

    println(person01.name)
    println(person01.age)
  }

}
