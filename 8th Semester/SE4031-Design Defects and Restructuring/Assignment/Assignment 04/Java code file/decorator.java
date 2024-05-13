public class CheeseAddition extends FoodItemDecorator {
  public CheeseAddition(FoodItem foodItem) {
    super(foodItem);
  }

  @Override
  public String getDisplayName() {
    return foodItem.getDisplayName() + " with Extra Cheese";
  }

  @Override
  public double getPriceWithAdditions() {
    return foodItem.getPriceWithAdditions() + 1.50; // Assuming extra cheese costs $1.50
  }
}
