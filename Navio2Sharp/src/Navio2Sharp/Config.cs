namespace Navio2Sharp
{
    internal static class Config
    {
        #if DEBUG
        public const string CNavio2Lib = "CNavio2-d";
        #else
        public const string CNavio2Lib = "CNavio2";
        #endif
    }
}
