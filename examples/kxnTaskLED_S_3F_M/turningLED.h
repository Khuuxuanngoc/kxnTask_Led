void LED_ON()
{
    if (this->level)
        digitalWrite(this->pin, this->level);
    else
        digitalWrite(this->pin, !this->level);
}
void LED_OFF()
{
    if (this->level)
        digitalWrite(this->pin, !this->level);
    else
        digitalWrite(this->pin, this->level);
}