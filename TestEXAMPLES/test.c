//IMAGE
/* int	main(void)
{
	void	*mlx; //display
	void	*mlx_win; //window
	t_data	image; //image

	mlx = mlx_init(); //display init
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); //window init
	image.img = mlx_new_image(mlx, 1920, 1080); //image init
} */

/* //HOOK

//Original function that handles key press events
void OnKeyPress(Key key)
{
    // Display a message
    DisplayMessage("You pressed the key: " + key);
}

// Hook function that intercepts key press events
void Hooked_OnKeyPress(Key key)
{
    // Perform additional behavior
    ChangeMessageColor(Color.Red);
    PlaySound("beep.wav");

    // Pass the event along to the original function
    OnKeyPress(key);
}

// Hook the OnKeyPress function
void HookOnKeyPress()
{
    // Replace the OnKeyPress function with our hook function
    OnKeyPress = Hooked_OnKeyPress;
}

// Main program loop
void Main()
{
    // Hook the OnKeyPress function
    HookOnKeyPress();

    // Wait for key press events
    while (true)
    {
        Key key = WaitForKeyPress();
        OnKeyPress(key);
    }
}
 */