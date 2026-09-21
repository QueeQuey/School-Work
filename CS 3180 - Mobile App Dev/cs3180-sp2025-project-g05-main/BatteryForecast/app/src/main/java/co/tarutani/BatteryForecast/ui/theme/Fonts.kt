package co.tarutani.BatteryForecast.ui.theme
// ui/theme/Fonts.kt

import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.googlefonts.Font
import androidx.compose.ui.text.googlefonts.GoogleFont
import co.tarutani.BatteryForecast.R

val provider = GoogleFont.Provider(
    providerAuthority = "com.google.android.gms.fonts",
    providerPackage = "com.google.android.gms",
    certificates = R.array.com_google_android_gms_fonts_certs
)

val calSansFontFamily = FontFamily(
    Font(googleFont = GoogleFont("Cal Sans"), fontProvider = provider)
)