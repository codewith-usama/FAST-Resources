public class SauceAddition extends FoodItemDecorator {
  public SauceAddition(FoodItem foodItem) {
    super(foodItem);
  }

  @Override
  public String getDisplayName() {
    return foodItem.getDisplayName() + " with Extra Sauce";
  }

  @Override
  public double getPriceWithAdditions() {
    return foodItem.getPriceWithAdditions() + 1.00; // Assuming extra sauce costs $1.00
  }
}
