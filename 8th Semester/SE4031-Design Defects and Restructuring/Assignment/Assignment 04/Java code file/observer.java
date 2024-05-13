public class BaconAddition extends FoodItemDecorator {
  public BaconAddition(FoodItem foodItem) {
    super(foodItem);
  }

  @Override
  public String getDisplayName() {
    return foodItem.getDisplayName() + " with Bacon";
  }

  @Override
  public double getPriceWithAdditions() {
    return foodItem.getPriceWithAdditions() + 2.00; // Assuming bacon costs $2.00
  }
}
