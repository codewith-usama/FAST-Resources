public interface FoodItemFactory {
  FoodItem createFoodItem(String category);
}

public class BurgerFactory implements FoodItemFactory {
  @Override
  public FoodItem createFoodItem(String category) {
    return new Burger();
  }
}
