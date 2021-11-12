package Day01

object _05ClassDemo {
  class Customer{
    var name:String = ""
    var sex:String = ""

    def printHello(msg:String) = println("Hello " + msg + " I am " + this.name)
  }

  def main(args: Array[String]): Unit = {
    val customer = new Customer
    customer.name = "邹鹏飞"
    customer.sex = "male"
    customer.printHello("范雨茹")
  }
}
